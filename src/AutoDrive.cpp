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
}

AutoDrive::~AutoDrive()
{
	adDrive = nullptr;
	delete adDrive;
}

bool AutoDrive::precisionDistance()
{
	if(distanceError() < 250 && distanceError() > -250)
	{
		adDrive->getCANTalon()->SetEncPosition(0);
		isAutoDrive = false;
		dis = 0;
		return true;
	}

	adDrive->addForwardSpeed(distanceError() / 500.0);
	return false;
}

float AutoDrive::distanceError()//encoder not attached to shaft
{
	SmartDashboard::PutNumber("enc pos", adDrive->getCANTalon()->GetEncPosition());
	SmartDashboard::PutNumber("dis", dis);
	return adDrive->getCANTalon()->GetEncPosition() - dis * 54.35;
}

void AutoDrive::setDistance(float distance)
{
	dis = distance;
	isAutoDrive = true;
}
