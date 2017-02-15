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
	printf("\nstart in precision distance");
	if(isAutoDrive)
	{
		printf("\nafter isAutoDrive");
		if(distanceError() > 1 || distanceError() < -1)
		{
			printf("\nafter deadzone for error");

			if(adDrive->abs(distanceError() / 10.0) < .3)
			{
				printf("\nafter max speed check");
				adDrive->addForwardSpeed(distanceError() / 10.0);
				return false;
			}
			adDrive->addForwardSpeed(adDrive->abs(distanceError())/(distanceError()) * .3);
			return false;

		}
		isAutoDrive = false;
	}
	//adDrive->getCANTalon()->SetEncPosition(0);
	//dis = 0;
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
		dis = distance;
		isAutoDrive = true;
	}

	return precisionDistance();
}

void AutoDrive::reset()
{
	adDrive->getCANTalon()->SetEncPosition(0);
	dis = 0;
}
