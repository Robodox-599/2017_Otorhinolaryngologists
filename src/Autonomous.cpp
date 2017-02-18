/*
 * Autonomous.cpp
 *
 *  Created on: Jan 19, 2017
 *      Author: Admin
 */
//Brandon's autonomouses


#define AUTONOMOUS



#ifdef AUTONOMOUS
#include "Autonomous.h"

Autonomous::Autonomous(Gears* autoGear, GyroDrive* autoTurning, AutoDrive* precisionDrive)
{
	gyroDrive = autoTurning;
	encDrive = precisionDrive;

	gear = autoGear;
	autoSteps = 0;
	isTurning = false;
	isDriving = false;
	isGears = false;
}

Autonomous::~Autonomous()
{


	gear = nullptr;


	delete gear;
}


void Autonomous::overlap1_2()
{
	if(autoSteps == 0)
	{

		isDriving = encDrive->setDistance(79.92);

		if(isDriving)
		{
			autoSteps = 1;
			isDriving = false;
		}
	}

	if(autoSteps == 1)
	{
		isTurning = gyroDrive->autoTurn(60);

		if(isTurning)
		{
			autoSteps = 2;
			isTurning = false;
		}
	}

	if(autoSteps == 2)
	{
		isDriving = encDrive->setDistance(38);

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
		else
		{
			gearsReset();
		}
	}

	if(autoSteps == 4)
	{
		isDriving = encDrive->setDistance(-38);

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
			isDriving = encDrive->setDistance(79.92);

			if(isDriving)
			{
				autoSteps = 1;
				isDriving = false;
			}
		}

		if(autoSteps == 1)
		{
			isTurning = gyroDrive->autoTurn(-60);

			if(isTurning)
			{
				autoSteps = 2;
				isTurning = false;
			}
		}

		if(autoSteps == 2)
		{
			isDriving = encDrive->setDistance(38);

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
			else
			{
				gearsReset();
			}
		}

		if(autoSteps == 4)
		{
			isDriving = encDrive->setDistance(-38);

			if(isDriving)
			{
				autoSteps = 5;
				isDriving = false;
			}
		}
}

//first autonomous
void Autonomous::auto1()
{
	overlap1_2();

	if(autoSteps == 5)
	 {
	  		isTurning = gyroDrive->autoTurn(-91.515);

	 		if(isTurning)
	  		{
	 			autoSteps = 6;
	 			isTurning = false;
	  		}
	  }

	  if(autoSteps == 6)
	  {
	  		isDriving = encDrive->setDistance(133.33);

	  		if(isDriving)
	  		{
	  			autoSteps = 7;
	  			isDriving = false;
	 		}
	  }

	  if(autoSteps == 7)
	  {
	  		isTurning = gyroDrive->autoTurn(58.485);

	  		if(isTurning)
	  		{
	  			autoSteps = 8;
	  			isTurning = false;
	  		}
	  }

	  if(autoSteps == 8)
	  {
	  		isDriving = encDrive->setDistance(35.14);

	  		if(isDriving)
	  		{
	  			autoSteps = 9;
	  			isDriving = false;
	  		}
	  }

	  if(autoSteps == 9)
	  {
	  		isDriving = encDrive->setDistance(-35.14);

	  		if(isDriving)
	  		{
	  			autoSteps = 10;
	  			isDriving = false;
	  		}
	  }

	  if(autoSteps == 10)
	  {
	 		isTurning = gyroDrive->autoTurn(90);

	  		if(isTurning)
	  		{
	  			autoSteps = 11;
	  			isTurning = false;
	  		}
	  }

	  if(autoSteps == 11)
	  {
	  		isDriving = encDrive->setDistance(163.56);

	  		if(isDriving)
	  		{
	  			isDriving = false;
	  		}
	  }
}

//Second Autonomous

void Autonomous::auto2()
{
	overlap1_2();

	if(autoSteps == 5)
	{
		isTurning = gyroDrive->autoTurn(-60);
		if(isTurning)
		{
			autoSteps = 3;
			isTurning = false;
		}
	}
	if(autoSteps == 6)
	{
		isDriving = encDrive->setDistance(260.17);
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
		isDriving = encDrive->setDistance(77);//was 79 changed 2/17/2017
		if(isDriving)
		{
			encDrive->reset();
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
		else
		{
			gearsReset();
		}
	}

	if(autoSteps == 2)
	{
		isDriving = encDrive->setDistance(-15);

		if(isDriving)
		{
			autoSteps = 3;
			encDrive->reset();
			isDriving = false;
		}
	}
}

//Fourth Autonomous

void Autonomous::auto4()
{
	overlap4_6_7();

	if(autoSteps == 5)
	{
		isTurning = gyroDrive->autoTurn(60);

		if(isTurning)
		{
			isTurning = false;
		}
	}
}

//Fifth Autonomous

void Autonomous::auto5()
{
	if(autoSteps == 0)
	{
		isDriving = encDrive->setDistance(338.56);

		if(isDriving)
		{
			isDriving = false;
		}
	}
}

//Sixth Autonomous

void Autonomous::auto6()
{
	overlap4_6_7();

	if(autoSteps == 5)
	{
		isTurning = gyroDrive->autoTurn(91.515);

		if(isTurning)
		{
			autoSteps = 5;
			isTurning = false;
		}
	}

	if(autoSteps == 6)
	{
		isDriving = encDrive->setDistance(113.33);

		if(isDriving)
		{
			autoSteps = 6;
			isDriving = false;
		}
	}

	if(autoSteps == 7)
	{
		isTurning = gyroDrive->autoTurn(58.485);

		if(isTurning)
		{
			autoSteps = 7;
			isTurning = false;
		}
	}

	if(autoSteps == 8)
	{
		isDriving = encDrive->setDistance(35.14);

		if(isDriving)
		{
			autoSteps = 9;
			isDriving = false;
		}
	}

	if(autoSteps == 9)
	{
		isDriving = encDrive->setDistance(-35.14);

		if(isDriving)
		{
			autoSteps = 10;
			isDriving = false;
		}
	}

	if(autoSteps == 10)
	{
		isTurning = gyroDrive->autoTurn(-90);

		if(isTurning)
		{
			autoSteps = 11;
			isTurning = false;
		}
	}

	if(autoSteps == 11)
	{
		isDriving = encDrive->setDistance(163.56);

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
		isTurning = gyroDrive->autoTurn(60);

		if(isTurning)
		{
			autoSteps = 6;
			isTurning = false;
		}
	}

	if(autoSteps == 6)
	{
		isDriving = encDrive->setDistance(260.17);

		if(isDriving)
		{
			autoSteps = 7;
			isDriving = false;
		}
	}
}

void Autonomous::gearsReset()
{
	isDriving = encDrive->setDistance(-10);
	isTurning = gyroDrive->autoTurn(-17);
	isTurning = gyroDrive->autoTurn(17);
	isDriving = encDrive->setDistance(10);
	isGears = gear->trapDoor();
}

#endif /*AUTONOMOUS*/
