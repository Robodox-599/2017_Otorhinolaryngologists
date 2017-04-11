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
	gyroValue = navX->GetYaw();

	if(gDrive->getIsJoystickTurn())
	{
		printf("\ngyro being reset by joystick\n");
		/*period->Start();
		hasTimerStarted = true;*/
		reset();
	}
	/*else if(!period->HasPeriodPassed(.1) && hasTimerStarted)
	{
		//Time is passing, are you?
		reset();
	}*/
	else if((calculateError()/.2 > GYRO_ERROR_DEADZONE && calculateError()/.2 < GYRO_ERROR_LIMIT) || (calculateError()/.2 < -GYRO_ERROR_DEADZONE && calculateError()/.2 > -GYRO_ERROR_LIMIT))
	{
		printf("\nrobot being corrected by gyro\n");
		if(gDrive->abs(calculateError()) < .2)
		{
			gDrive->addTurnSpeed(calculateError());
		}
		gDrive->addTurnSpeed(gDrive->abs(calculateError()) / (calculateError())*(.08));

		return false;
	}
	/*else
	{
		//reset();
		//period->Stop();
		//period->Reset();
		//hasTimerStarted = false;
	}*/
	return true;
}

bool GyroDrive::autoTurn(float angle)
{
	desiredAngle = angle;
	return straightDrive();
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
