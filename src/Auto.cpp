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

void Autonomous::overlap1_2()
{
	if(autoSteps == 0)
		{
			isDriving = drive->autoEncDistance(79.92);

			if(isDriving)
			{
				autoSteps = 1;
				isDriving = false;
			}
		}

		if(autoSteps == 1)
		{
			isTurning = drive->setAutoTurning(60);

			if(isTurning)
			{
				autoSteps = 2;
				isTurning = false;
			}
		}

		if(autoSteps == 2)
		{
			isDriving = drive->autoEncDistance(38);

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
			isDriving = drive->autoEncDistance(-38);

			if(isDriving)
			{
				autoSteps = 5;
				isDriving = false;
			}
		}
}


void Autonomous::overlap4_6_7()
{
	if(autoSteps == 0)
		{
			isDriving = drive->autoEncDistance(79.92);

			if(isDriving)
			{
				autoSteps = 1;
				isDriving = false;
			}
		}

		if(autoSteps == 1)
		{
			isTurning = drive->setAutoTurning(-60);

			if(isTurning)
			{
				autoSteps = 2;
				isTurning = false;
			}
		}

		if(autoSteps == 2)
		{
			isDriving = drive->autoEncDistance(38);

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
			isDriving = drive->autoEncDistance(-38);

			if(isDriving)
			{
				autoSteps = 5;
				isDriving = false;
			}
		}
}

//Second Auto

void Auto::auto2()
{
	overlap1_2();

	if(autoSteps == 5)
	{
		isTurning = drive->setAutoTurning(-60);
		if(isTurning)
		{
			autoSteps = 3;
			isTurning = false;
		}
	}
	if(autoSteps == 6)
	{
		isDriving = drive->autoEncDistance(260.17);
		if(isDriving)
		{
			isDriving = false;
		}
	}
}

//Fourth Auto

void Auto::auto4()
{
	overlap4_6_7();

	if(autoSteps == 5)
	{
		isTurning = drive->setAutoTurning(60);

		if(isTurning)
		{
			isTurning = false;
		}
	}
}

//Sixth Auto

void Auto::auto6()
{
	overlap4_6_7();

	if(autoSteps == 5)
	{
		isTurning = drive->setAutoTurning(91.515);

		if(isTurning)
		{
			autoSteps = 5;
			isTurning = false;
		}
	}

	if(autoSteps == 6)
	{
		isDriving = drive->autoEncDistance(113.33);

		if(isDriving)
		{
			autoSteps = 6;
			isDriving = false;
		}
	}

	if(autoSteps == 7)
	{
		isTurning = drive->setAutoTurning(58.485);

		if(isTurning)
		{
			autoSteps = 7;
			isTurning = false;
		}
	}

	if(autoSteps == 8)
	{
		isDriving = drive->autoEncDistance(35.14);

		if(isDriving)
		{
			autoSteps = 9;
			isDriving = false;
		}
	}

	if(autoSteps == 9)
	{
		isDriving = drive->autoEncDistance(-35.14);

		if(isDriving)
		{
			autoSteps = 10;
			isDriving = false;
		}
	}

	if(autoSteps == 10)
	{
		isTurning = drive->setAutoTurning(-90);

		if(isTurning)
		{
			autoSteps = 11;
			isTurning = false;
		}
	}

	if(autoSteps == 11)
	{
		isDriving = drive->autoEncDistance(163.56);

		if(isDriving)
		{
			isDriving = false;
		}
	}
}
