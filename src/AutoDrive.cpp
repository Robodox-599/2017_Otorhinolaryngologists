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
}

AutoDrive::~AutoDrive()
{
	adDrive = nullptr;
	delete adDrive;
}

bool AutoDrive::precisionDistance(float distance)
{
	if(distanceError(distance) > 250 || distanceError(distance) < -250)
	{
		adDrive->addForwardSpeed(distanceError(distance) / 10000);
		return false;
	}

	adDrive->getCANTalon()->SetEncPosition(0);
	return true;
}

float AutoDrive::distanceError(float distance)
{
	return adDrive->getCANTalon()->GetEncPosition() - distance * 54.35;
}
