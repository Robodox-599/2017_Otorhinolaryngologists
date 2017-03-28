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
	period = new Timer();

	navX->ZeroYaw();

	gyroValue = 0;
	desiredAngle = 0;
	hasTimerStarted = false;

	isAutoTurning = false;
}

GyroDrive::~GyroDrive()
{
	gDrive = nullptr;
	navX = nullptr;
	period = nullptr;

	delete gDrive;
	delete navX;
	delete period;
}

bool GyroDrive::straightDrive()
{
	gyroValue = navX->GetYaw();

	if(gDrive->getIsJoystickTurn())
	{
		reset();
	}

	else if((calculateError() > GYRO_ERROR_DEADZONE && calculateError() < GYRO_ERROR_LIMIT) || (calculateError() < -GYRO_ERROR_DEADZONE && calculateError() > -GYRO_ERROR_LIMIT))
	{

		if(gDrive->abs(calculateError()) < .2)//tune value
		{
			gDrive->addTurnSpeed(calculateError() * .08);//was .2

			return false;
		}

		gDrive->addTurnSpeed(gDrive->abs(calculateError()) / (calculateError())*(.2));//tune value

		return false;
	}

	desiredAngle = 0;

	return true;
}

bool GyroDrive::autoTurn(float angle)
{
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

	gyroValue = 0;
	desiredAngle = 0;
	isAutoTurning = false;
}

bool GyroDrive::isGyroStable()
{
	if(navX->GetRawGyroX() < 2 && navX->GetRawGyroY() < 2)//&& navX->GetRawGyroZ() < 2)
	{
		return true;
	}
	return false;
}
