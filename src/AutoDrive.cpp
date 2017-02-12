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
	if(isAutoDrive)
	{
		if(distanceError() > 250 || distanceError() < -250)
		{
			if(adDrive->abs(distanceError() / 500.0) < .3)
			{
				adDrive->addForwardSpeed(distanceError() / 500.0);
				return false;
			}
			adDrive->addForwardSpeed(adDrive->abs(distanceError() / 500.0)/(distanceError() / 500.0) * .3);
			return false;

		}

		adDrive->getCANTalon()->SetEncPosition(0);
		isAutoDrive = false;
		dis = 0;
	}
	return true;
}

float AutoDrive::distanceError()//encoder not attached to shaft
{
	SmartDashboard::PutNumber("enc pos", adDrive->getCANTalon()->GetEncPosition());
	SmartDashboard::PutNumber("dis", dis * 54.35);
	return -dis * 54.35 + adDrive->getCANTalon()->GetEncPosition();//switch this if switch encoder motor
}

void AutoDrive::setDistance(float distance)
{
	if(!isAutoDrive)
	{
		dis = -distance;
		isAutoDrive = true;
	}
}
