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

//Second Auto

void Auto::auto2()
{
	if(autoSteps == 0)
	{
		isDriving = drive->autoEncDistance(6);
		if(isDriving)
		{
			autoSteps = 1;
			isDriving = false;
		}
	}

	if(autoSteps == 1)
	{
		isTurning = drive->setAutoTurning(90);
		if(isTurning)
		{
			autoSteps = 2;
			isTurning = false;
		}
	}

	if(autoSteps == 2)
	{
		isDriving = drive->autoEncDistance(10);
		if(isDriving)
		{
			autoSteps = 3;
			isDriving = false;
		}
	}

	if(autoSteps == 3)
	{
		isGears = gear->trapDoor();
		if(isGears)
		{
			autoSteps = 2;
			isGears = false;
		}
	}

	if(autoSteps == 4)
	{
		isDriving = drive->autoEncDistance(-1);
		if(isDriving)
		{
			autoSteps = 3;
			isDriving = false;
		}
	}

	if(autoSteps == 5)
	{
		isTurning = drive->setAutoTurning(90);
		if(isTurning)
		{
			autoSteps = 3;
			isTurning = false;
		}
	}
	if(autoSteps == 6)
	{
		isDriving = drive->autoEncDistance(6);
		if(isDriving)
		{
			autoSteps = 4;
			isDriving = false;
		}
	}

	if(autoSteps == 7)
	{
		isTurning = drive->setAutoTurning(1);
		if(isTurning)
		{
			autoSteps = 8;
			isTurning = false;
		}
	}

	if(autoSteps == 8)
	{
		isDriving = drive->autoEncDistance(6);
		if(isDriving)
		{
			isDriving = false;
		}
	}
}

//Fourth Auto

void Auto::auto4()
{
	if(autoSteps == 0)
	{
		isDriving = drive->autoEncDistance(6);

		if(isDriving)
		{
			autoSteps = 1;
			isDriving = false;
		}
	}

	if(autoSteps == 1)
	{
		isTurning = drive->setAutoTurning(45);

		if(isTurning)
		{
			autoSteps = 2;
			isTurning = false;
		}
	}

	if(autoSteps == 2)
	{
		isDriving = drive->autoEncDistance(6);

		if(isDriving)
		{
			autoSteps = 3;
			isDriving = false;
		}
	}

	if(autoSteps == 3)
	{
		isGears = gear->trapDoor();

		if(isGears)
		{
			isGears = false;
		}
	}
	if(autoSteps == 4)
	{
		isDriving = drive->autoEncDistance(-1);
	}
}

//Sixth Auto

void Auto::auto6()
{
	if(autoSteps == 0)
	{
		isDriving = drive->autoEncDistance(6);

		if(isDriving)
		{
			autoSteps = 1;
			isDriving = false;
		}
	}

	if(autoSteps == 1)
	{
		isTurning = drive->setAutoTurning(45);

		if(isTurning)
		{
			autoSteps = 2;
			isTurning = false;
		}
	}

	if(autoSteps == 2)
	{
		isDriving = drive->autoEncDistance(6);

		if(isDriving)
		{
			autoSteps = 3;
			isDriving = false;
		}
	}

	if(autoSteps == 3)
	{
		isGears = gear->trapDoor();

		if(isGears)
		{
			autoSteps = 4;
			isGears = false;
		}
	}

	if(autoSteps == 4)
	{
		isDriving = drive->autoEncDistance(-1);
		if(isDriving)
		{
			autoSteps = 5;
			isDriving = false;
		}
	}

	if(autoSteps == 5)
	{
		isTurning = drive->setAutoTurning(45);

		if(isTurning)
		{
			autoSteps = 5;
			isTurning = false;
		}
	}

	if(autoSteps == 6)
	{
		isDriving = drive->autoEncDistance(6);

		if(isDriving)
		{
			autoSteps = 6;
			isDriving = false;
		}
	}

	if(autoSteps == 7)
	{
		isTurning = drive->setAutoTurning(45);

		if(isTurning)
		{
			autoSteps = 7;
			isTurning = false;
		}
	}

	if(autoSteps == 8)
	{
		isDriving = drive->autoEncDistance(6);

		if(isDriving)
		{
			isDriving = false;
		}
	}
}
