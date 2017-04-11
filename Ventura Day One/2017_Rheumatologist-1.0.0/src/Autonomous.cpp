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
#include <cmath>

Autonomous::Autonomous(Gears* autoGear, GyroDrive* autoTurning, AutoDrive* precisionDrive, VisionTracking* vt, Drive* dr)
{
	gyroDrive = autoTurning;
	encDrive = precisionDrive;

	pxyDrive = vt;

	drive = dr;

	time = new Timer();

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


void Autonomous::overlap1_2()
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
		gyroDrive->straightDrive();
		isDriving = encDrive->setDistance(38);

		if(isDriving)
		{
			encDrive->reset();
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
		/*else
		{
			gearsReset();
		}*/
	}

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

void Autonomous::overlap4_6_7()
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
			gyroDrive->straightDrive();
			isDriving = encDrive->setDistance(38);

			if(isDriving)
			{
				encDrive->reset();
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
			/*else
			{
				gearsReset();
			}*/
		}

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
	//printf("autoStep: %d", autoSteps);
	isGears = gear->trapDoor();
	if(isGears)
	{
		//Wait(3);
		encDrive->reset();
		autoSteps = 2;
		isGears = false;
	}

	if(autoSteps == 0)
	{
		//encDrive->linerizedDrive();
		gyroDrive->straightDrive();
		isDriving = encDrive->setDistance(79);//was 79 changed 2/17/2017
		//printf("false");
		if(isDriving)
		{
			//Wait(10);
			encDrive->reset();
			autoSteps = 1;
			isDriving = false;
		}
	}

	/*else if(autoSteps == 2)
	{


		drive->drive(0,0);
		Wait(5);

		drive->updateAllMotors();
		Wait(2);
		drive->addForwardSpeed(0);
		drive->updateAllMotors();
		isDriving = true;
		if(isDriving)
		{
			drive->drive(0,0);
			autoSteps = 3;
			isDriving = false;
		}
	}

	else if(autoSteps == 1)
	{
		time->Start();
		gyroDrive->straightDrive();

		if(time->HasPeriodPassed(.5))
		{

			printf("\nwobble");
			gearsReset();
			autoSteps = 1.5;
			//gyroDrive->straightDrive();
		}
		else
		{
			printf("\nnot wobble");
			drive->addForwardSpeed(.2);
			isGears = gear->trapDoor();
		}


		if(isGears)
		{
			//Wait(3);
			autoSteps = 2;
			isGears = false;
		}
	}*/

	else if(autoSteps == 1)
	{

		isGears = gear->trapDoor();

		if(!isGears)
		{
			//Wait(3);
			//autoSteps = 2;
			//isGears = false;
			autoSteps = 1.1;
		}
		else
		{
			autoSteps = 2;
			isGears = false;
		}
	}

	else if(autoSteps == 1.1)
	{
		gyroDrive->straightDrive();
		isDriving = encDrive->setDistance(-3);

		if(isDriving)
		{

			encDrive->reset();
			autoSteps = 1.2;
			isDriving = false;
		}
	}
	else if(autoSteps == 1.2)
	{
		gyroDrive->straightDrive();
		isDriving = encDrive->setDistance(7);
		if(isDriving)
		{
			encDrive->reset();
			autoSteps = 1;
			isDriving = false;
		}
	}

	else if(autoSteps == 2)
	{
		isDriving = encDrive->setDistance(-8);
		gyroDrive->straightDrive();

		if(isDriving)
		{
			//Wait(1);
			autoSteps = 3;
			encDrive->reset();
			isDriving = false;
			gear->trapDoorClose(true);
		}
	}

	/*else if(autoSteps == 3)//test this step
	{
		isDriving = encDrive->setDistance(8);
		gyroDrive->straightDrive();

		if(isDriving)
		{
			//Wait(1);
			autoSteps = 3.1;
			encDrive->reset();
			isDriving = false;
		}
	}*/
	else if(autoSteps == 3)
	{
		/*isDriving = encDrive->setDistance(-12);
		gyroDrive->straightDrive();

		if(isDriving)
		{
			//Wait(1);
			autoSteps = 4;
			encDrive->reset();
			isDriving = false;
		}*/

		isTurning = gyroDrive->autoTurn(-90);
		if(isTurning)
		{
			autoSteps = 4;
			isTurning = false;
		}
	}
	/*
	else if(autoSteps == 4)
	{
		isDriving = encDrive->setDistance(-7);

		if(isDriving)
		{
			autoSteps = 5;
			encDrive->reset();
			isDriving = false;
		}
	}*/
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
	drive->addForwardSpeed(-.2);
	if(time->HasPeriodPassed(4))
	{
		time->Stop();
		time->Reset();
	}
	//drive->addTurnSpeed(-sin( (drive->getCANTalon()->GetEncPosition() + drive->getCANTalonLeft()->GetEncPosition())/2 * 1/250.0 ) * .2);
}


void Autonomous::autoReset()
{
	autoSteps = 0;
	printf("\n\nreset Auto Setps\n\n");
}

#endif /*AUTONOMOUS*/
