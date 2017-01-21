/*
 * Autonomous.cpp
 *
 *  Created on: Jan 19, 2017
 *      Author: Admin
 */
//Brandon's autonomouses

#include <Autonomous.h>

Autonomous::Autonomous(Drive* autoDrive, Gears* autoGear)
{
	drive = autoDrive;
	gear = autoGear;
	autoSteps = 0;
	isTurning = false;
	isDriving = false;
	isGears = false;
}

Autonomous::~Autonomous()
{
	drive = nullptr;
	gear = nullptr;

	delete drive;
	delete gear;

}


void Autonomous::auto1()
{
	if(autoSteps == 0)
	{
		//Move Forward

		if(isDriving && isGears)
		{
			autoSteps = 1;
			isDriving = false;
			isGears = false;
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

		if(isTurning)
		{
			autoSteps = 3;
			isTurning = false;
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

		if(isTurning)
		{
			autoSteps = 5;
			isTurning = false;
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


//Third Autonomous

void Autonomous::auto3()
{
	if(autoSteps == 0)
	{
		// Drive forward

		if(isDriving)
		{
			autoSteps = 1;
			isDriving = false;
		}
	}

	if(autoSteps == 1)
	{
		//Put gear

		if(isGears)
		{
			isGears = false;
		}
	}
}

//Fifth Autonomous

void Autonomous::auto5()
{
	if(autoSteps == 0)
	{
		//Drive forward

		if(isDriving)
		{
			isDriving = false;
		}
	}
}

//Seventh Autonomous

void Autonomous::auto7()
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
		//Turn

		if(isTurning)
		{
			autoSteps = 2;
			isTurning = false;
		}
	}

	if(autoSteps == 2)
	{
		//Drive forward

		if(isDriving)
		{
			autoSteps = 3;
			isDriving = false;
		}
	}

	if(autoSteps == 3)
	{
		//Put gear

		if(isGears)
		{
			autoSteps = 4;
			isGears = false;
		}
	}

	if(autoSteps == 4)
	{
		//Turn

		if(isTurning)
		{
			autoSteps = 5;
			isTurning = false;
		}
	}

	if(autoSteps == 5)
	{
		//Drive forward

		if(isDriving)
		{
			autoSteps = 6;
			isDriving = false;
		}
	}

	if(autoSteps == 6)
	{
		//Turn
	}
}
