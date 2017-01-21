/*
 * Auto.cpp
 *
 *  Created on: Jan 19, 2017
 *      Author: Admin
 */
//Brandon's autonomouses

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

//First Auto

void Auto::auto1()
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


//Third Auto

void Auto::auto3()
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

//Fifth Auto

void Auto::auto5()
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

//Seventh Auto

void Auto::auto7()
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
		//Drive forward (Halfway not touching ball deposit)

		if(isDriving)
		{
			autoSteps = 6;
			isDriving = false;
		}
	}

	if(autoSteps == 6)
	{
		//Turn

		if(isTurning)
		{
			autoSteps = 7;
			isTurning = false;
		}
	}

	if(autoSteps == 7)
	{
		//Drive forward

		if(isDriving)
		{
			isDriving = false;
		}
	}
}
