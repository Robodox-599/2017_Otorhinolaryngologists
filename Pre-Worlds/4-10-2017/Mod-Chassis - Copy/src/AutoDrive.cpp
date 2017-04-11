/*
* AutoDrive.cpp
*
*  Created on: Jan 30, 2017
*      Author: tons-of-carls
*/

#include "AutoDrive.h"

AutoDrive::AutoDrive(Drive* d)
{
	adDrive = d;

	isAutoDrive = false;
	dis = 0;
	intgError = 0;
}

AutoDrive::~AutoDrive()
{
	adDrive = nullptr;
	delete adDrive;
}

bool AutoDrive::precisionDistance()
{
	if((distanceError() > 1 || distanceError() < -1) || adDrive->abs(adDrive->getCANTalon()->GetEncVel()) > 75 || adDrive->abs(adDrive->getCANTalonLeft()->GetEncVel()) > 75)//adDrive->abs(dis) > adDrive->abs(0.01975 * averageEncoders()))
	{
		if(adDrive->abs(distanceError() / 50.0) < .45)
		{
			intgError += 0.001;
			adDrive->addForwardSpeed(distanceError() / 50.0 + adDrive->sign(distanceError()) * intgError);
			return false;
		}
		adDrive->addForwardSpeed(adDrive->abs(distanceError()) / (distanceError()) * .45);
		return false;

	}
	reset();
	return true;
}

float AutoDrive::distanceError()//-dis * 54.35
{
	return dis + 0.0184 * averageEncoders();
}
//.8 enc rotation / 1 wheel rotation
//1.25 wheel rotation / 1 enc rotation
//


int AutoDrive::averageEncoders()
{
	return (adDrive->getCANTalon()->GetEncPosition() + adDrive->getCANTalonLeft()->GetEncPosition())/2;
}

bool AutoDrive::setDistance(float distance)
{
	dis = distance;

	return precisionDistance();
}

void AutoDrive::reset()
{

	intgError = 0;
	adDrive->getCANTalon()->SetEncPosition(0);
	adDrive->getCANTalonLeft()->SetEncPosition(0);
	dis = 0;
}

