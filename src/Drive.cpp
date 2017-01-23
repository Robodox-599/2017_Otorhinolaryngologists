/*
 * Drive.cpp
 *
 *  Created on: Mar 27, 2016
 *      Author: Robodox 599
 */
//Gyro and
#include "Drive.h"

Drive::Drive()
{

	navX = new AHRS(SPI::Port::kMXP);

	//left drive
	frontLeftDrive = new CANTalon(0);	//port 13
	backLeftDrive = new CANTalon(1);	//port 15
	frontRightDrive = new CANTalon(3);	//port 0
	backRightDrive = new CANTalon(2);	//port 2

	forwardSpeed = 0;
	turnSpeed = 0;

	globalGyro = 0;

	navX->ZeroYaw();

	gyroValue = navX->GetYaw();
	refAngle = gyroValue;
	error = 0;
	
	isAutoTurning = false;

	isDriving = false;
	autoDrivingError = 0;
	distance = 0;
}


Drive::~Drive()
{
	//left drive
	delete frontLeftDrive;
	delete backLeftDrive;

	//right drive
	delete frontRightDrive;
	delete backRightDrive;

	//left drive
	frontLeftDrive = nullptr;
	backLeftDrive = nullptr;

	//right drive
	frontRightDrive = nullptr;
	backRightDrive = nullptr;
}


/*************************************************/

/**
 * drive: get desired speed values and assign them to motors
 * @param xAxis is the joystick x-axis
 * @param yAxis is the joystick y-axis
 *
 */
void Drive::drive(float xAxis, float yAxis)
{
	gyroValue = navX->GetYaw();

	error = refAngle - gyroValue;

	autoDrivingError = distance - frontLeftDrive->GetEncPosition();

	setForwardSpeed(yAxis);
	setTurnSpeed(xAxis);
	
	resetGyro();

	updateLeftMotors(forwardSpeed - turnSpeed);
	updateRightMotors(forwardSpeed + turnSpeed);
}

/**
 * setForwardSpeed: update forward speed with input
 * @param forward is the forward/backward speed
 */
void Drive::setForwardSpeed(float forward)
{
	if(forward >= .3)
	{
		forwardSpeed = 2 * (forward - .3) * (forward - .3);
	}
	else if(forward <= -.3)
	{
		forwardSpeed = 2 * (-forward - .3) * (-forward - .3);
	}

	else if(autoDrivingError <= -2 || autoDrivingError >= 2)
	{
		forwardSpeed = autoDrivingError*0.00001;
	}
	/*else if(frontLeftDrive->GetEncPosition() < abs(encTargetPosition))
	{
		 forwardSpeed = error*kp;

	}
	else if(forwardSpeed > 1)
	{
		forwardSpeed = 1;
	}*/
	else
	{
		forwardSpeed = 0;
	}
}

/**
 * setTurnSpeed: update turn speed with input
 * @param turn is the turn speed
 */
void Drive::setTurnSpeed(float turn)//continuous turning problem
{
	if(turn >= .3)
	{
		resetGyro(-5);
		turnSpeed = 2 * (turn - .3) * (turn - .3) * (1 - abs(forwardSpeed));
	}
	else if(turn <= -.3)
	{
		resetGyro(5);
		turnSpeed = 2 * (-turn - .3) * (-turn - .3) * (1 - abs(forwardSpeed));
	}
	else if(error >= .5 || error <= -.5)
	{
		turnSpeed = kp * error;
	}
	else
	{
		turnSpeed = 0;
	}
}

/**
 * updateLeftMotors: set left motors to desired speed
 * @param speed is the desired speed input
 */
void Drive::updateLeftMotors(float speed)//put on an x^2 curve
{
	frontLeftDrive->Set(-speed);//2x speed note
	backLeftDrive->Set(-speed);
}

/**
 * updateRightMotors: set right motors to desired speed; reverses right motors
 * @param speed is the desired speed input
 */
void Drive::updateRightMotors(float speed)
{
	frontRightDrive->Set(speed);
	backRightDrive->Set(speed);
}

bool Drive::setAutoTurning(float angle) // range -180 to 180
{

	if(!isAutoTurning)
	{
		refAngle = angle;
		isAutoTurning = true;
	}
	
	drive(0, 0);

	if(error == 0)
	{
		resetGyro();
		return true;
	}
	
	return false;
}

void Drive::resetGyro(float offSet)
{
	globalGyro = globalGyro + navX->GetYaw() + offSet;//check if this works
	navX->ZeroYaw();
	gyroValue = navX->GetYaw();
	refAngle = offSet;
	isAutoTurning = false;
}

bool Drive::globalAutoTurning(float angle)//range: 0 - 360 NOT ready for use
{
	if(angle - ((int)globalGyro % 360) > ((int)globalGyro % 360) - (angle - 360))
	{
		return setAutoTurning(refAngle + (((int)globalGyro % 360) - (angle - 360)));
	}
	else
	{
		return setAutoTurning(refAngle - (angle - ((int)globalGyro % 360)));
	}
}

float Drive::abs(float num)
{
	if(num < 0)
	{
		return -num;
	}
	return num;
}

bool Drive::autoEncDistance(float desiredDistance)
{


	if(!isDriving)
	{
		frontLeftDrive->SetEncPosition(0);
		distance = desiredDistance*54.35;
		isDriving = true;
	}

	drive(0, 0);

	if(autoDrivingError == 0)
	{
		//resetGyro();
		return true;
	}

	return false;

	/*desiredTicks = desiredDistance*54.35; //54.35 is ticks/in
	encStartPosition = frontLeftDrive->GetEncPosition();
	encTargetPosition = encStartPosition + desiredTicks;

	encError = encTargetPosition - frontLeftDrive->GetEncPosition();*/
}


