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

	SmartDashboard::PutNumber("Gyro offset", navX->GetAngleAdjustment());
	if(!isAutoTurning)
	{
		gyroValue = navX->GetYaw();
	}

	SmartDashboard::PutNumber("Gyro Value", gyroValue);

	if(gDrive->getIsJoystickTurn())
	{
		printf("\ngyro being reset by joystick\n");
		reset();
	}

	else if((calculateError()/.2 > GYRO_ERROR_DEADZONE && calculateError()/.2 < GYRO_ERROR_LIMIT) || (calculateError()/.2 < -GYRO_ERROR_DEADZONE && calculateError()/.2 > -GYRO_ERROR_LIMIT))
	{
		printf("\nrobot being corrected by gyro\n");
		if(gDrive->abs(calculateError()) < .13)//tune value
		{
			printf("\nError Value input inside if: %d\n", calculateError());
			gDrive->addTurnSpeed(calculateError());
			return false;
		}

		printf("\nError Value input out side if: %d\n", gDrive->abs(calculateError()) / (calculateError())*(.08));
		gDrive->addTurnSpeed(gDrive->abs(calculateError()) / (calculateError())*(.13));//tune value

		return false;
	}

	isAutoTurning = false;

	return true;
}

bool GyroDrive::autoTurn(float angle)
{
	gyroValue = angle;
	isAutoTurning = true;

	if(straightDrive())
	{
		reset();
		return true;
	}

	return false;
}

float GyroDrive::calculateError()
{
	return (gyroValue - desiredAngle) * .2;
}

void GyroDrive::reset()
{
	navX->ZeroYaw();

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
