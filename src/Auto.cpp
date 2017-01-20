/*
 * Auto.cpp
 *
 *  Created on: Jan 19, 2017
 *      Author: Admin
 */
#include "Auto.h"

Auto::Auto(Drive* autoDrive, Gears* autoGear)
{
	drive = autoDrive;
	gear = autoGear;
	autoSteps = 0;
	isTurning = false;
	isDriving = false;
	isGears = false;
}

Auto::~Auto()
{
	drive = nullptr;
	gear = nullptr;

	delete drive;
	delete gear;
}




void Auto::auto1()
{
	if(autoSteps == 0)
	{
		//Move Forward

		if(isDriving)
		{
			autoSteps = 1;
			isDriving = false;
		}
	}

	if(autoSteps == 1)
	{
		//Put Gear

		if(isGears)
		{
			autoSteps = 2;
			isGears = false;
		}
	}

	if(autoSteps == 2)
	{
		//Turn

		if(isDriving)
		{
			autoSteps = 3;
			isDriving = false;
		}
	}

	if(autoSteps == 3)
	{
		//Drive forward (hit ball deposit)

		if(isDriving)
		{
			autoSteps = 4;
			isDriving = false;
		}
	}

	if(autoSteps == 4)
	{
		//Turn

		if(isDriving)
		{
			autoSteps = 5;
			isDriving = false;
		}
	}

	if(autoSteps == 5)
	{
		//Drive forward

		if(isDriving)
		{
			isDriving = false;
		}
	}
}

void Auto::auto2()
{
	if(autoSteps == 0)
	{
		//Move forward
		if(isDriving)
		{
			autoSteps = 1;
			isDriving = false;
		}
	}

	if(autoSteps == 1)
	{
		//Put Gear
		if(isGears)
		{
			autoSteps = 2;
			isGears = false;
		}
	}
	if(autoSteps == 2)
	{
		//turn 90 degrees
		if(isTurning)
		{
			autoSteps = 3;
			isTurning = false;
		}
	}
	if(autoSteps == 3)
	{
		//drive <170"
		if(isDriving)
		{
			autoSteps = 4;
			isDriving = false;
		}
	}
	if(autoSteps == 4)
	{
		//turn 90 degrees
		if(isTurning)
		{
			autoSteps = 5;
			isTurning = false;
		}
	}
	if(autoSteps == 5)
	{
		//drive 120"
		if(isDriving)
		{
			isDriving = false;
		}
	}
}

void Auto::auto4()
{
	if(autoSteps == 0)
	{
		//drive 112"
		if()
	}
}

