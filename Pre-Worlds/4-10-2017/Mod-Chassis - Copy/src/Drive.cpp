/*
 * Drive.cpp
 *
 *  Created on: Jan 30, 2017
 *      Author: tons-of-carls
 */

#include "Drive.h"

Drive::Drive()
{
	//Left Drive
	frontLeftDrive = new CANTalon(7);
	backLeftDrive = new CANTalon(10);

	//Right Drive
	frontRightDrive = new CANTalon(8);
	backRightDrive = new CANTalon(6);

	frontLeftDrive->SetVoltageRampRate(60);
	backLeftDrive->SetVoltageRampRate(60);

	frontRightDrive->SetVoltageRampRate(60);
	backRightDrive->SetVoltageRampRate(60);

	shifter = new DoubleSolenoid(0,1);

	//general Variables
	forwardSpeed = 0;
	turnSpeed = 0;

	shifterButtonPress = false;

	isJoystickTurn = false;
	isJoystickForward = false;

	rightOffset = 0;
	leftOffset = 0;
}


Drive::~Drive()
{
	//left drive
	delete frontLeftDrive;
	delete backLeftDrive;

	//right drive
	delete frontRightDrive;
	//delete backRightDrive;

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
	setForwardSpeed(yAxis);
	setTurnSpeed(xAxis);
}

/**
 * Drive Equation: 2x^2 - 1.2x + .18
 * setForwardSpeed: update forward speed with input
 * @param forward is the forward/backward speed
 */
void Drive::setForwardSpeed(float forward)
{
	forwardSpeed = 0;

	leftOffset = 0;
	rightOffset = 0;

	if(forward >= .05)
	{
		forwardSpeed += (forward - .05) * (forward - .05);
		isJoystickForward = true;
	}
	else if(forward <= -.05)
	{
		forwardSpeed += -(-forward - .05) * (-forward - .05);
		isJoystickForward = true;
	}
	else
	{
		isJoystickForward = false;
	}
}


/**
 * Drive Equation:
 * setTurnSpeed: update turn speed with input
 * @param turn is the turn speed
 */
void Drive::setTurnSpeed(float turn)//continuous turning problem
{
	turnSpeed = 0;

	leftOffset = 0;
	rightOffset = 0;

	if(turn >= .17)//changed deadzone because it was messing with the linerized drive -> .18
	{
		turnSpeed += (-1.19 * turn + .207) * (-1.19 * turn + .207) * (1 - (.48*abs(forwardSpeed)));//.5 * (turn - .05) * (turn - .05) * (1 - (.48*abs(forwardSpeed)));
		isJoystickTurn = true;
	}
	else if(turn <= -.17)//-.2
	{
		turnSpeed += -(1.19 * turn + .207) * (1.19 * turn + .207) * (1 - (.48*abs(forwardSpeed)));//-.5 * (-turn - .05) * (-turn - .05) * (1 - (.48*abs(forwardSpeed)));
		isJoystickTurn = true;
	}
	else
	{
	  isJoystickTurn = false;
	}
}


/**
 * updateAllMotors: updates all motors using the updateLeftMotors and updateRightMotors function
 */
void Drive::updateAllMotors()
{
	updateLeftMotors(forwardSpeed + turnSpeed + leftOffset);
	updateRightMotors(forwardSpeed - turnSpeed + rightOffset);
}

/**
 * updateLeftMotors: set left motors to desired speed
 * @param speed is the desired speed input
 */
void Drive::updateLeftMotors(float speed)
{
	SmartDashboard::PutNumber("Left Speed", speed);

	frontLeftDrive->Set(speed);
	backLeftDrive->Set(speed);
}

/**
 * updateRightMotors: set right motors to desired speed; reverses right motors
 * @param speed is the desired speed input
 */
void Drive::updateRightMotors(float speed)
{
	SmartDashboard::PutNumber("Right Speed", speed);


	frontRightDrive->Set(-speed);//positive input motor runs counter clockwise on mod chassis may be because of gear box but check this for every robot
	backRightDrive->Set(-speed);
}












/**
 * addForwardSpeed: increases the forward speed by increment
 * @param increment is the amount to increase the forward speed by
 */
void Drive::addForwardSpeed(float increment)
{
	forwardSpeed += increment;
}




/**
 * addTurnSpeed: increases the turn speed by increment
 * @param increment is the amount to increase the turn speed by
 */
void Drive::addTurnSpeed(float increment)
{
	SmartDashboard::PutNumber("turn inc in drive", increment);
	turnSpeed += increment;
}


void Drive::addOffsetLeftTurn(float offset)//assuming negative enc value is forward
{
	if(offset < 0)
	{
		leftOffset += offset;//-
	}
	else
	{
		rightOffset += offset;//+
	}
}

void Drive::addOffsetRightTurn(float offset)
{
	if(offset < 0)
	{
		rightOffset += offset;//-
	}
	else
	{
		leftOffset += offset;//+
	}
}

/**
 * getIsJoystickTurn: gets the value of isJoystickTurn
 * if the driver is turning using the joystick then isJoystickTurn will be true
 * @return the value of isJoystickTurn
 */
bool Drive::getIsJoystickTurn()
{
	return isJoystickTurn;
}

/**
 * getIsJoystickForward: gets the value of isJoystickForward
 * if the driver is driving forward or backwards using the joystick then isJoystickforwards will be true
 * @return the value of isJoystickforwards
 */
bool Drive::getIsJoystickForward()
{
	return isJoystickForward;
}

float Drive::abs(float num)
{
	if(num < 0)
	{
		return -num;
	}
	return num;
}

int Drive::sign(float value)
{
	if(value < 0)
	{
		return -1;
	}
	return 1;
}

CANTalon* Drive::getCANTalon()
{
	return frontRightDrive;
}

CANTalon* Drive::getCANTalonLeft()
{
	return frontLeftDrive;
}

void Drive::shift(bool toggleShift)
{
	if(toggleShift && shifterButtonPress)
		{
			if(shifter->Get() == DoubleSolenoid::Value::kForward)
			{
				shifter->Set(DoubleSolenoid::Value::kReverse);
				setRampRates(40);
			}
			else
			{
				shifter->Set(DoubleSolenoid::Value::kForward);
				setRampRates(80);
			}
			shifterButtonPress = false;
		}

		if(!toggleShift && !shifterButtonPress)
		{
			shifterButtonPress = true;
		}
}

string Drive::getShiftState()
{
	if(shifter->Get() == DoubleSolenoid::Value::kForward)
	{
		return "Low Gear";
	}

	return "High Gear";
}

void Drive::setRampRates(int voltage)
{
	frontLeftDrive->SetVoltageRampRate(voltage);
	backLeftDrive->SetVoltageRampRate(voltage);

	frontRightDrive->SetVoltageRampRate(voltage);
	backRightDrive->SetVoltageRampRate(voltage);
}


void Drive::setLowGear()
{
	shifter->Set(DoubleSolenoid::Value::kReverse);
	setRampRates(80);
}
