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
	if(distanceError() > .5 || distanceError() < -.5)
	{
		if(adDrive->abs(distanceError() / 10.0) < .3)
		{
			adDrive->addForwardSpeed(distanceError() / 10.0);
			return false;
		}
		adDrive->addForwardSpeed(adDrive->abs(distanceError())/(distanceError()) * .3);
		return false;

	}
	reset();
	return true;
}

float AutoDrive::distanceError()//-dis * 54.35
{
	return dis - 0.018 * adDrive->getCANTalon()->GetEncPosition();
}
//.8 enc rotation / 1 wheel rotation
//1.25 wheel rotation / 1 enc rotation
//

bool AutoDrive::setDistance(float distance)
{
	dis = distance;

	return precisionDistance();
}

void AutoDrive::reset()
{
	adDrive->getCANTalon()->SetEncPosition(0);
	adDrive->getCANTalonLeft()->SetEncPosition(0);
	dis = 0;
}

