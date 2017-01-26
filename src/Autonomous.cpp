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


void Autonomous::overlap1_2()
{
	if(autoSteps == 0)
		{
			isDriving = drive->autoEncDistance(79.92); //PARAMETERS ARBRITRARY

			if(isDriving)
			{
				autoSteps = 1;
				isDriving = false;
			}
		}

		if(autoSteps == 1)
		{
			isTurning = drive->setAutoTurning(60); //PARAMETERS ARBRITRARY

			if(isTurning)
			{
				autoSteps = 2;
				isTurning = false;
			}
		}

		if(autoSteps == 2)
		{
			isDriving = drive->autoEncDistance(38); //PARAMETERS ARBRITRARY

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
			isDriving = drive->autoEncDistance(-38); //PARAMETERS ARBRITRARY

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
			isDriving = drive->autoEncDistance(79.92); //PARAMETERS ARBRITARY

			if(isDriving)
			{
				autoSteps = 1;
				isDriving = false;
			}
		}

		if(autoSteps == 1)
		{
			isTurning = drive->setAutoTurning(-60); //PARAMETERS ARBRITARY

			if(isTurning)
			{
				autoSteps = 2;
				isTurning = false;
			}
		}

		if(autoSteps == 2)
		{
			isDriving = drive->autoEncDistance(38); //PARAMETERS ARBRITARY

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

void Autonomous::auto1()
{
	overlap1_2();

	if(autoSteps == 5)
	 {
	  		isTurning = drive->setAutoTurning(-91.51456682);

	 		if(isTurning)
	  		{
	 			autoSteps = 6;
	 			isTurning = false;
	  		}
	  }

	  if(autoSteps == 6)
	  {
	  		isDriving = drive->autoEncDistance(133.33);

	  		if(isDriving)
	  		{
	  			autoSteps = 7;
	  			isDriving = false;
	 		}
	  }

	  if(autoSteps == 7)
	  {
	  		isTurning = drive->setAutoTurning(-58.48543318);

	  		if(isTurning)
	  		{
	  			autoSteps = 8;
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
	 		isTurning = drive->setAutoTurning(90);

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

//Third Autonomous

void Autonomous::auto3()
{
	if(autoSteps == 0)
	{
		isDriving = drive->autoEncDistance(79); //PARAMETERS ARBRITARY
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
		isDriving = drive->autoEncDistance(338.56); //PARAMETERS ARBRITARY

		if(isDriving)
		{
			isDriving = false;
		}
	}
}

//Seventh Autonomous

void Autonomous::auto7()
{
	overlap4_6_7();

	if(autoSteps == 5)
	{
		isTurning = drive->setAutoTurning(60); //PARAMETERS ARBRITARY

		if(isTurning)
		{
			autoSteps = 6;
			isTurning = false;
		}
	}

	if(autoSteps == 6)
	{
		isDriving = drive->autoEncDistance(260.17); //PARAMETERS ARBRITARY

		if(isDriving)
		{
			autoSteps = 7;
			isDriving = false;
		}
	}
}


