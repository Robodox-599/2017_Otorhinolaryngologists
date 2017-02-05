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
		period->Start();
		hasTimerStarted = true;
	}
	else if(!period->HasPeriodPassed(.5) && hasTimerStarted)
	{
		//Time is passing, are you?
		reset();
	}
	else if((calculateError()*100 > GYRO_ERROR_DEADZONE && calculateError()*100 < GYRO_ERROR_LIMIT) || (calculateError()*100 < -GYRO_ERROR_DEADZONE && calculateError()*100 > -GYRO_ERROR_LIMIT))
	{
		if(gDrive->abs(calculateError()) < .25)
		{
			gDrive->addTurnSpeed(calculateError());
		}
		gDrive->addTurnSpeed(gDrive->abs(calculateError()) / (calculateError())*(.25));

		return false;
	}
	else
	{
		//reset();
		period->Stop();
		period->Reset();
		hasTimerStarted = false;
	}
	return true;
}

bool GyroDrive::autoTurn(float angle)
{
	desiredAngle = angle;
	return straightDrive();
}

float GyroDrive::calculateError()
{
	return (desiredAngle - gyroValue) * .01;
}

void GyroDrive::reset()
{
	navX->ZeroYaw();

	gyroValue = 0;
	desiredAngle = 0;
}


