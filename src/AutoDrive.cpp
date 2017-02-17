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
	printf("\nEnc Velocity: %d", adDrive->getCANTalon()->GetEncVel());

	if(isAutoDrive)
	{
		if(distanceError() > .5 || distanceError() < -.5 || adDrive->getCANTalon()->GetEncVel() > 2 || adDrive->getCANTalon()->GetEncVel() < -2)
		{
			if(adDrive->abs(distanceError() / 10.0) < .3)
			{
				adDrive->addForwardSpeed(distanceError() / 10.0);
				return false;
			}
			adDrive->addForwardSpeed(adDrive->abs(distanceError())/(distanceError()) * .3);
			return false;

		}
		isAutoDrive = false;
	}
	reset();
	return true;
}

float AutoDrive::distanceError()//-dis * 54.35
{
	SmartDashboard::PutNumber("enc pos in inches", 0.019 * adDrive->getCANTalon()->GetEncPosition());
	SmartDashboard::PutNumber("dis", dis);
	return dis - 0.019 * adDrive->getCANTalon()->GetEncPosition();//going double the distance
}
//.8 enc rotation / 1 wheel rotation
//1.25 wheel rotation / 1 enc rotation
//

bool AutoDrive::setDistance(float distance)
{
	if(!isAutoDrive)
	{
		dis = distance - 10;
		isAutoDrive = true;
	}

	return precisionDistance();
}

void AutoDrive::reset()
{
	adDrive->getCANTalon()->SetEncPosition(0);
	dis = 0;
}
