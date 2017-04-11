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
	if(autoSteps < 2)
	{
		isGears = gear->trapDoor();
	}
	if(isGears)
	{
		encDrive->reset();
		resetTimer();
		autoSteps = 2;
		isGears = false;

		printf("\nGOT gear and reset\n");
	}

	if(autoSteps == 0)
	{

		time->Start();
		gyroDrive->straightDrive();
		isDriving = encDrive->setDistance(79);//was 79 changed 2/17/2017

		if(isDriving || time->HasPeriodPassed(2))
		{
			encDrive->reset();
			resetTimer();
			autoSteps = 1;
			isDriving = false;
		}
	}

	else if(autoSteps == 1)
	{

		isGears = gear->trapDoor();

		if(!isGears)
		{
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
		isDriving = encDrive->setDistance(-8);

		time->Start();

		if(isDriving || time->HasPeriodPassed(1))
		{

			encDrive->reset();
			resetTimer();
			autoSteps = 1.2;
			isDriving = false;
		}
	}
	else if(autoSteps == 1.2)
	{
		gyroDrive->straightDrive();
		isDriving = encDrive->setDistance(12);

		time->Start();
		if(isDriving || time->HasPeriodPassed(1))
		{
			encDrive->reset();
			resetTimer();
			autoSteps = 1;
			isDriving = false;
		}
	}

	else if(autoSteps == 2)
	{
		printf("\nlast drive backwards\n");

		//isDriving = encDrive->setDistance(-30);

		gyroDrive->straightDrive();

		drive->drive(0, -.5);

		time->Start();

		if(time->HasPeriodPassed(2))
		{
			printf("\nlast backing up done\n");
			autoSteps = 3;

			resetTimer();

			//encDrive->reset();
			isDriving = false;
			gear->trapDoorClose(true);
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
		gyroDrive->straightDrive();

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

void Autonomous::resetTimer()
{
	time->Stop();
	time->Reset();
}













//All version of Auto 3
//conversion factor = 55.5555555 ticks / inch
void Autonomous::linearAuto3()
{
	while(!(drive->getCANTalon()->GetEncPosition() >= 4388 || drive->getCANTalonLeft()->GetEncPosition() >= 4388))
	{
		drive->drive(0,0);
		drive->addForwardSpeed(.3);
		gyroDrive->straightDrive();
		drive->updateAllMotors();
	}
	drive->drive(0,0);
	drive->updateAllMotors();
	encDrive->reset();

	Wait(.5);

	while(!gear->trapDoor())
	{
		time->Start();

		if(autoSteps == 0)
		{
			drive->drive(0,0);
			drive->addForwardSpeed(-.3);
			gyroDrive->straightDrive();
			drive->updateAllMotors();

			if(time->HasPeriodPassed(1))
			{
				autoSteps = 1;
				resetTimer();
			}
		}

		else if(autoSteps == 1)
		{
			drive->drive(0,0);
			drive->addForwardSpeed(.3);
			gyroDrive->straightDrive();
			drive->updateAllMotors();

			if(time->HasPeriodPassed(1.5))
			{
				autoSteps = 0;
				resetTimer();
			}
		}
	}
	encDrive->reset();
	drive->drive(0,0);
	drive->updateAllMotors();

	Wait(1);

	while(!(drive->getCANTalon()->GetEncPosition() <= -111 || drive->getCANTalonLeft()->GetEncPosition() <= -111))
	{
		drive->drive(0,0);
		drive->addForwardSpeed(-.3);
		gyroDrive->straightDrive();
		drive->updateAllMotors();
	}

	gear->trapDoorClose(true);

	Wait(15);
}


void Autonomous::linearBasicAuto1(float angle) //use 60 or -60 for angle
{
	while(!(drive->getCANTalon()->GetEncPosition() >= 4388 || drive->getCANTalonLeft()->GetEncPosition() >= 4388))
	{
		drive->drive(0,0);
		drive->addForwardSpeed(.3);
		gyroDrive->straightDrive();
		drive->updateAllMotors();
	}
	drive->drive(0,0);
	drive->updateAllMotors();
	encDrive->reset();

	Wait(.5);

	while(true)
	{
		drive->drive(0,0);
		if(gyroDrive->autoTurn(angle))
		{
			break;
		}
		drive->updateAllMotors();
	}

	drive->drive(0,0);
	drive->updateAllMotors();
	encDrive->reset();

	Wait(.5);

	while(!(drive->getCANTalon()->GetEncPosition() >= 2111 || drive->getCANTalonLeft()->GetEncPosition() >= 2111))
	{
		drive->drive(0,0);
		drive->addForwardSpeed(.3);
		gyroDrive->straightDrive();
		drive->updateAllMotors();
	}
	drive->drive(0,0);
	drive->updateAllMotors();
	encDrive->reset();

	while(!gear->trapDoor())
	{
		time->Start();

		if(autoSteps == 0)
		{
			drive->drive(0,0);
			drive->addForwardSpeed(-.3);
			gyroDrive->straightDrive();
			drive->updateAllMotors();

			if(time->HasPeriodPassed(1))
			{
				autoSteps = 1;
				resetTimer();
			}
		}

		else if(autoSteps == 1)
		{
			drive->drive(0,0);
			drive->addForwardSpeed(.3);
			gyroDrive->straightDrive();
			drive->updateAllMotors();

			if(time->HasPeriodPassed(1.5))
			{
				autoSteps = 0;
				resetTimer();
			}
		}
	}
	encDrive->reset();
	drive->drive(0,0);
	drive->updateAllMotors();

	Wait(1);

	while(!(drive->getCANTalon()->GetEncPosition() <= -2111 || drive->getCANTalonLeft()->GetEncPosition() <= -2111))
	{
		drive->drive(0,0);
		drive->addForwardSpeed(-.3);
		gyroDrive->straightDrive();
		drive->updateAllMotors();
	}
	drive->drive(0,0);
	drive->updateAllMotors();
	encDrive->reset();
}

#endif /*AUTONOMOUS*/
