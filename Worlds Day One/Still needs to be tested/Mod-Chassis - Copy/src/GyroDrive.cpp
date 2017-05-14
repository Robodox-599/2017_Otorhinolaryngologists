/*
 * GyroDrive.cpp
 *
 *  Created on: Jan 30, 2017
 *      Author: tons-of-carls
 */

#include "GyroDrive.h"

GyroDrive::GyroDrive(Drive* d)
{
	gDrive = d;
	navX = new AHRS(SPI::Port::kMXP);

	navX->ZeroYaw();

	joystickTurn = false;

	gyroValue = 0;
	desiredAngle = 0;
	integrator = 0;
	maxTurnSpeed = 0.13;

	kp = 0.06;
}

GyroDrive::~GyroDrive()
{
	gDrive = nullptr;
	navX = nullptr;

	delete gDrive;
	delete navX;
}

bool GyroDrive::straightDrive()
{

	gyroValue = navX->GetYaw();

	SmartDashboard::PutNumber("Gyro Value", gyroValue);

	SmartDashboard::PutNumber("Gyro Error", calculateError());

	if(gDrive->getIsJoystickTurn() && !joystickTurn)
	{
		joystickTurn = true;
		teleopSet();
	}

	else if((gDrive->abs(navX->GetRate()) == 0) && joystickTurn)
	{
		joystickTurn = false;
		teleopSet();
	}

	else if(joystickTurn)
	{
		teleopSet();
	}

	else if((calculateError() > GYRO_ERROR_DEADZONE && calculateError() < GYRO_ERROR_LIMIT) || (calculateError() < -GYRO_ERROR_DEADZONE && calculateError() > -GYRO_ERROR_LIMIT)) //|| (gDrive->abs(navX->GetRate()) > .5))
	{


		if(gDrive->abs(calculateError())* kp < maxTurnSpeed)//tune value
		{
			integrator += 0.0015;//added in an integrator // was 0.0001
			gDrive->addTurnSpeed(calculateError()* kp + gDrive->sign(calculateError()) * integrator);//check if robot will occilate with new max speed of .17 was .13

			return false;
		}

		gDrive->addTurnSpeed(gDrive->sign(calculateError()) * (maxTurnSpeed + integrator));//tune value

		return false;
	}


	maxTurnSpeed = 0.13;
	desiredAngle = 0;
	integrator  = 0;

	return true;
}

bool GyroDrive::autoTurn(float angle)//, float aveEnc)
{

	/*if(angle < 0)
	{
		gDrive->addOffsetLeftTurn(aveEnc * 0.001);
	}
	else
	{
		gDrive->addOffsetRightTurn(aveEnc * 0.001);
	}*/
	maxTurnSpeed = .27;//.16 -> .19

	desiredAngle = angle;
	return straightDrive();
}

float GyroDrive::calculateError()
{
	return (desiredAngle - gyroValue);//was gyroValue - desiredAngle
}

void GyroDrive::reset()
{
	navX->ZeroYaw();

	kp = 0.06;//.06

	gyroValue = 0;
	desiredAngle = 0;
}

bool GyroDrive::isGyroStable()
{
	if(navX->GetRawGyroX() < 2 && navX->GetRawGyroY() < 2)//&& navX->GetRawGyroZ() < 2)
	{
		return true;
	}
	return false;
}

void GyroDrive::teleopSet()
{
	navX->ZeroYaw();

	kp = 0.3;

	gyroValue = 0;
	desiredAngle = 0;
}
