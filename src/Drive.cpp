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
	needsReset = false;
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
		needsReset = true;
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

void Drive::setAutoTurning(float angle)
{
	refAngle = angle;
	isAutoTurning = true;
}

void Drive::endAutoTurning()
{
	if(isAutoTurning && needsReset)
	{
		resetGyro();
	}
}

void Drive::resetGyro(float offSet)
{
	globalGyro = globalGyro + navX->GetYaw() + offSet;//check if this works
	navX->ZeroYaw();
	gyroValue = navX->GetYaw();
	refAngle = offSet;
	needsReset = false;
	isAutoTurning = false;
}

void Drive::globalAutoTurning(float angle)//0 - 360
{
	if(angle - ((int)globalGyro % 360) > ((int)globalGyro % 360) - (angle - 360))
	{
		setAutoTurning(refAngle + (((int)globalGyro % 360) - (angle - 360)));
	}
	else
	{
		setAutoTurning(refAngle - (angle - ((int)globalGyro % 360)));
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



