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
		isDriving = drive->autoEncDistance(43.25); //PARAMETERS ARBRITRARY

		if(isDriving)
		{
			autoSteps = 1;
			isDriving = false;
		}
	}

	if(autoSteps == 1)
	{
		isTurning = drive->setAutoTurning(10); //PARAMETERS ARBRITRARY

		if(isTurning)
		{
			autoSteps = 2;
			isTurning = false;
		}
	}

	if(autoSteps == 2)
	{
		isDriving = drive->autoEncDistance(14); //PARAMETERS ARBRITRARY

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
		isDriving = drive->setAutoTurning(-10); //PARAMETERS ARBRITRARY

		if(isDriving)
		{
			autoSteps = 5;
			isDriving = false;
		}
	}

	if(autoSteps == 5)
	{
		isTurning = drive->setAutoTurning(120); //PARAMETERS ARBRITARY

		if(isTurning)
		{
			autoSteps = 6;
			isTurning = false;
		}
	}

	if(autoSteps == 6)
	{
		isDriving = drive->autoEncDistance(10); //(hit ball deposit) //PARAMETERS ARBRITARY

		if(isDriving)
		{
			autoSteps = 7;
			isDriving = false;
		}
	}

	if(autoSteps == 7)
	{
		isTurning = drive->setAutoTurning(120); //PARAMETERS ARBRITARY

		if(isTurning)
		{
			autoSteps = 8;
			isTurning = false;
		}
	}

	if(autoSteps == 8)
	{
		isDriving = drive->autoEncDistance(11); //PARAMETERS ARBRITARY

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
		isDriving = drive->autoEncDistance(78); //PARAMETERS ARBRITARY
		if(isDriving)
		{
			autoSteps = 1;
			isDriving = false;
		}
	}

	if(autoSteps == 1)
	{
		isGears = gear->trapDoor();

		if(isGears)
		{
			autoSteps = 2;
			isGears = false;
		}
	}

	if(autoSteps == 2)
	{
		isDriving = drive->autoEncDistance(-15);

		if(isDriving)
		{
			isDriving = false;
		}
	}
}

//Fifth Autonomous

void Autonomous::auto5()
{
	if(autoSteps == 0)
	{
		isDriving = drive->autoEncDistance(285); //PARAMETERS ARBRITARY

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
		isDriving = drive->autoEncDistance(14); //PARAMETERS ARBRITARY

		if(isDriving)
		{
			autoSteps = 1;
			isDriving = false;
		}
	}

	if(autoSteps == 1)
	{
		isTurning = drive->setAutoTurning(120); //PARAMETERS ARBRITARY

		if(isTurning)
		{
			autoSteps = 2;
			isTurning = false;
		}
	}

	if(autoSteps == 2)
	{
		isDriving = drive->autoEncDistance(15); //PARAMETERS ARBRITARY

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
		isDriving = drive->autoEncDistance(-6);

		if(isDriving)
		{
			autoSteps = 5;
			isDriving = false;
		}
	}

	if(autoSteps == 5)
	{
		isTurning = drive->setAutoTurning(120); //PARAMETERS ARBRITARY

		if(isTurning)
		{
			autoSteps = 6;
			isTurning = false;
		}
	}

	if(autoSteps == 6)
	{
		isDriving = drive->autoEncDistance(16); //PARAMETERS ARBRITARY

		if(isDriving)
		{
			autoSteps = 7;
			isDriving = false;
		}
	}

	if(autoSteps == 7)
	{
		isTurning = drive->setAutoTurning(120); //PARAMETERS ARBRITARY

		if(isTurning)
		{
			autoSteps = 8;
			isTurning = false;
		}
	}

	if(autoSteps == 8)
	{
		isDriving = drive->autoEncDistance(17); //PARAMETERS ARBRITARY

		if(isDriving)
		{
			isDriving = false;
		}
	}
}
