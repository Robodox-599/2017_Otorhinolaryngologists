/*
 * Drive.cpp
 *
 *  Created on: Jan 30, 2017
 *      Author: tons-of-carls
 */

#define OLD_DRIVE_CODE

#ifdef ARC_DRIVE_CODE
#include "Drive.h"

Drive::Drive()
{
	//Left Drive
	frontLeftDrive = new Talon(0);      //port 13
	backLeftDrive = new Talon(1);       //port 15

	//Right Drive
	frontRightDrive = new CANTalon(8);  //port 0
	backRightDrive = new CANTalon(7);   //port 2

	//general Variables
	forwardSpeed = 0;
	turnSpeed = 0;

	isJoystickTurn = false;
	isJoystickForward = false;
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
	setTurnSpeed(xAxis);
	setForwardSpeed(yAxis);
}

/**
 * Drive Equation: 2x^2 - 1.2x + .18
 * setForwardSpeed: update forward speed with input
 * @param forward is the forward/backward speed
 */
void Drive::setForwardSpeed(float forward)
{
	forwardSpeed = 0;

	if((turnSpeed > 0 || turnSpeed < 0) && abs(forward) > .3)
	{
		forwardSpeed += (1/.7) * forward * abs(turnSpeed);//linear velocity = radius * angular velocity
	}
	else if(forward >= .3)
	{
		forwardSpeed += 2 * (forward - .3) * (forward - .3);
		isJoystickForward = true;
	}
	else if(forward <= -.3)
	{
		forwardSpeed += -2 * (-forward - .3) * (-forward - .3);
		isJoystickForward = true;
	}
	else
	{
		isJoystickForward = false;
	}
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
 * Drive Equation: 2x^2 - 1.2x + .18
 * setTurnSpeed: update turn speed with input
 * @param turn is the turn speed
 */
void Drive::setTurnSpeed(float turn)//continuous turning problem
{
	turnSpeed = 0;

	if(turn >= .3)
	{
		turnSpeed += 2 * (turn - .3) * (turn - .3);
		isJoystickTurn = true;
	}
	else if(turn <= -.3)
	{
		turnSpeed += -2 * (-turn - .3) * (-turn - .3);
		isJoystickTurn = true;
	}
	else
	{
		isJoystickTurn = false;
	}
}

/**
 * addTurnSpeed: increases the turn speed by increment
 * @param increment is the amount to increase the turn speed by
 */
void Drive::addTurnSpeed(float increment)
{
  turnSpeed += increment;
}

/**
 * updateAllMotors: updates all motors using the updateLeftMotors and updateRightMotors function
 */
void Drive::updateAllMotors()
{
  updateLeftMotors(forwardSpeed - turnSpeed);
	updateRightMotors(forwardSpeed + turnSpeed);
}

/**
 * updateLeftMotors: set left motors to desired speed
 * @param speed is the desired speed input
 */
void Drive::updateLeftMotors(float speed)
{
	frontLeftDrive->Set(-speed);
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

CANTalon* Drive::getCANTalon()
{
	return frontRightDrive;
}

#endif /*NEW_DRIVE_CODE*/





















#ifdef OLD_DRIVE_CODE
#include "Drive.h"

Drive::Drive()
{
	//Left Drive
	frontLeftDrive = new CANTalon(3);      //port 13
	backLeftDrive = new CANTalon(4);       //port 15

	//Right Drive
	frontRightDrive = new CANTalon(1);  //port 0
	backRightDrive = new CANTalon(2);   //port 2

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
 * addForwardSpeed: increases the forward speed by increment
 * @param increment is the amount to increase the forward speed by
 */
void Drive::addForwardSpeed(float increment)
{
	forwardSpeed += increment;
}

/**
 * Drive Equation:
 * setTurnSpeed: update turn speed with input
 * @param turn is the turn speed
 */
void Drive::setTurnSpeed(float turn)//continuous turning problem
{
	turnSpeed = 0;

	if(turn >= .05)
	{
		turnSpeed += .5 * (turn - .05) * (turn - .05) * (1 - (.48*abs(forwardSpeed)));
		isJoystickTurn = true;
	}
	else if(turn <= -.05)
	{
		turnSpeed += -.5 * (-turn - .05) * (-turn - .05) * (1 - (.48*abs(forwardSpeed)));
		isJoystickTurn = true;
	}
	else
	{
	  isJoystickTurn = false;
	}
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

/**
 * updateAllMotors: updates all motors using the updateLeftMotors and updateRightMotors function
 */
void Drive::updateAllMotors()
{
	updateLeftMotors(forwardSpeed - turnSpeed);
	updateRightMotors(forwardSpeed + turnSpeed);
}

/**
 * updateLeftMotors: set left motors to desired speed
 * @param speed is the desired speed input
 */
void Drive::updateLeftMotors(float speed)
{
	frontLeftDrive->Set(-speed);
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

CANTalon* Drive::getCANTalon()
{
	return frontRightDrive;
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

#endif /*OLD_DRIVE_CODE*/
