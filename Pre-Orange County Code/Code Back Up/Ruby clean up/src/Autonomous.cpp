/*
 * Autonomous.cpp
 *
 *  Created on: Jan 19, 2017
 *      Author: Admin
 */
//Brandon's autonomouses

#include "Autonomous.h"
#include <cmath>

Autonomous::Autonomous(Gears* autoGear, GyroDrive* autoTurning, AutoDrive* precisionDrive, VisionTracking* vt, Drive* dr)
{
	gyroDrive = autoTurning;
	encDrive = precisionDrive;

	pxyDrive = vt;

	drive = dr;

	time = new Timer();

	breakAuto = new Timer();

	gear = autoGear;
	autoSteps = 0;
	isTurning = false;
	isDriving = false;
	isGears = false;
}

Autonomous::~Autonomous()
{
	gear = nullptr;
	gyroDrive = nullptr;
	encDrive = nullptr;
	pxyDrive = nullptr;

	delete gear;
	delete gyroDrive;
	delete encDrive;
	delete pxyDrive;
}

void Autonomous::auto1()
{
	if(autoSteps == 0)
	{

		gyroDrive->straightDrive();
		isDriving = encDrive->setDistance(79.92);

		if(isDriving)
		{
			encDrive->reset();
			autoSteps = 1;
			isDriving = false;
		}
	}
}

void Autonomous::auto2()
{
	auto1();

	if(autoSteps == 1)
	{
		isTurning = gyroDrive->autoTurn(60);

		if(isTurning)
		{
			autoSteps = 2;
			isTurning = false;
		}
	}
}

void Autonomous::auto3()
{
	auto2();

	if(autoSteps == 2)
	{
		if(pxyDrive->trackTurn())
		{
			gyroDrive->straightDrive();
		}
		else
		{
			gyroDrive->reset();
		}

		isDriving = encDrive->setDistance(38);

		if(isDriving)
		{
			encDrive->reset();
			autoSteps = 3;
			isDriving = false;
		}
	}
}

void Autonomous::auto4()
{
	auto3();
	if(autoSteps == 3)
	{

		isGears = gear->trapDoor();
		drive->addForwardSpeed(.2);
		if(isGears)
		{
			encDrive->reset();
			autoSteps = 4;
			isGears = false;
		}
	}
}

void Autonomous::auto5()
{
	auto3();

	if(autoSteps == 4)
	{
		gyroDrive->straightDrive();
		isDriving = encDrive->setDistance(-38);

		if(isDriving)
		{
			encDrive->reset();
			autoSteps = 5;
			isDriving = false;
		}
	}
}
