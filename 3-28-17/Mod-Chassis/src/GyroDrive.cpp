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

	gyroValue = 0;
	desiredAngle = 0;
	integrator = 0;
	maxTurnSpeed = 0.13;
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

	if(gDrive->getIsJoystickTurn())
	{
		reset();
	}

	else if((calculateError() > GYRO_ERROR_DEADZONE && calculateError() < GYRO_ERROR_LIMIT) || (calculateError() < -GYRO_ERROR_DEADZONE && calculateError() > -GYRO_ERROR_LIMIT))
	{
		integrator += 0.0001;//added in an integrator

		if(gDrive->abs(calculateError())*.08 < maxTurnSpeed)//tune value
		{
			gDrive->addTurnSpeed(calculateError()*.08 + gDrive->sign(calculateError()) * integrator);//check if robot will occilate with new max speed of .17 was .13

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

bool GyroDrive::autoTurn(float angle)
{
	maxTurnSpeed = .16;

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
}

bool GyroDrive::isGyroStable()
{
	if(navX->GetRawGyroX() < 2 && navX->GetRawGyroY() < 2)//&& navX->GetRawGyroZ() < 2)
	{
		return true;
	}
	return false;
}
