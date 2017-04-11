/*
 * Autonomous.cpp
 *
 *  Created on: Jan 19, 2017
 *      Author: Admin
 */
//Brandon's autonomouses

#include "Autonomous.h"

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


//Left: side = 60, Right: side = -60
//Left gear or right gear auto
//With Pixy correction
void Autonomous::auto1(float side)
{
	if(autoSteps == 0)
	{
		gyroDrive->straightDrive();
		isDriving = encDrive->setDistance(79);

		if(isDriving)
		{
			encDrive->reset();
			autoSteps = 1;
			isDriving = false;
		}
	}

	if(autoSteps == 1)
	{
		isTurning = gyroDrive->autoTurn(side, 0);

		if(isTurning)
		{
			encDrive->reset();
			gyroDrive->reset();
			autoSteps = 2;
			isTurning = false;
		}
	}

	if(autoSteps == 2)
	{
		time->Start();
		if(!pxyDrive->trackTurn())
		{
			gyroDrive->straightDrive();
		}
		else
		{
			gyroDrive->reset();
		}

		isDriving = encDrive->setDistance(38);

		if(isDriving || time->HasPeriodPassed(2))
		{
			timerReset();
			encDrive->reset();
			autoSteps = 3;
			isDriving = false;
		}
	}

	if(autoSteps == 3)
	{

		isGears = true;
		gear->trapDoorOpen(true);

		if(isGears)
		{
			encDrive->reset();
			autoSteps = 4;
			isGears = false;
		}
	}

	if(autoSteps == 4)
	{
		gyroDrive->straightDrive();
		isDriving = encDrive->setDistance(-38);

		if(isDriving)
		{
			gear->trapDoorClose(true);
			encDrive->reset();
			autoSteps = 5;
			isDriving = false;
		}
	}
}


//Middle Gear
//With pixy correction
void Autonomous::auto2()
{
	if(autoSteps == 0)
	{
		time->Start();
		if(!pxyDrive->trackTurn())
		{
			gyroDrive->straightDrive();
		}
		else
		{
			gyroDrive->reset();
		}

		isDriving = encDrive->setDistance(79);

		if(isDriving || time->HasPeriodPassed(2))
		{
			timerReset();
			encDrive->reset();
			autoSteps = 1;
			isDriving = false;
		}
	}

	if(autoSteps == 1)
	{

		isGears = true;
		gear->trapDoorOpen(true);

		if(isGears)
		{
			encDrive->reset();
			autoSteps = 2;
			isGears = false;
		}
	}

	if(autoSteps == 2)
	{
		gyroDrive->straightDrive();
		isDriving = encDrive->setDistance(-38);

		if(isDriving)
		{
			gear->trapDoorClose(true);
			encDrive->reset();
			autoSteps = 3;
			isDriving = false;
		}
	}
}




//red: side = -60, blue: side = 60
//Left gear or right gear auto
void Autonomous::boilerSide(int side)
{
	if(autoSteps == 0)
	{
		gyroDrive->straightDrive();
		isDriving = encDrive->setDistance(67);

		if(isDriving)
		{
			encDrive->reset();
			autoSteps = 1;
			isDriving = false;
		}
	}

	if(autoSteps == 1)
	{
		isTurning = gyroDrive->autoTurn(side, encDrive->averageEncoders());
		//drive->addOffset(encDrive->averageEncoders() * 0.001);

		if(isTurning)
		{
			encDrive->reset();
			gyroDrive->reset();
			autoSteps = 2;
			isTurning = false;
		}
	}

	if(autoSteps == 2)
	{
		time->Start();
		if(time->HasPeriodPassed(1))
		{
			encDrive->reset();
			gyroDrive->reset();
			autoSteps = 3;
		}
	}

	if(autoSteps == 3)
	{
		time->Start();

		gyroDrive->straightDrive();
		isDriving = encDrive->setDistance(89);

		if(isDriving || time->HasPeriodPassed(2))
		{
			timerReset();
			encDrive->reset();
			autoSteps = 4;
			isDriving = false;
		}
	}

	if(autoSteps == 4)
	{

		isGears = true;
		gear->trapDoorOpen(true);

		if(isGears)
		{
			encDrive->reset();
			autoSteps = 5;
			isGears = false;
			isDriving = false;
		}
	}

	if(autoSteps == 5)
	{

		printf("\nStep 5 reached\n");
		gyroDrive->straightDrive();
		isDriving = encDrive->setDistance(-38);

		SmartDashboard::PutBoolean("is Driving", isDriving);

		if(isDriving)
		{
			printf("\nStep 5 ended\n");
			gear->trapDoorClose(true);
			//encDrive->reset();
			autoSteps = 6;
			isDriving = false;
		}
	}
}

//Middle Gear
void Autonomous::middleGear()
{
	SmartDashboard::PutNumber("autosteps", autoSteps);

	if(autoSteps == 0)
	{
		time->Start();
		gyroDrive->straightDrive();
		isDriving = encDrive->setDistance(83);//78 -> 81 ->

		if(isDriving)
		{
			timerReset();
			encDrive->reset();
			autoSteps = 1;
			isDriving = false;
		}
		else if(time->HasPeriodPassed(7))
		{
			printf("\ntime out\n");

			timerReset();
			encDrive->reset();
			autoSteps = 20;
			isDriving = false;
		}
	}

	auto5(1);

	if(autoSteps == 1)
	{
		isGears = true;
		printf("before open trap door door");
		gear->trapDoorOpen(true);

		drive->drive(0, 0);
		drive->updateAllMotors();
		Wait(2);

		if(isGears)
		{
			encDrive->reset();
			autoSteps = 2;
			isGears = false;
		}
	}

	if(autoSteps == 2)
	{
		gear->trapDoorOpen(true);
		gyroDrive->straightDrive();
		isDriving = encDrive->setDistance(-38);

		if(isDriving)
		{
			gear->trapDoorClose(true);
			encDrive->reset();
			autoSteps = 3;
			isDriving = false;
		}
	}
}

//red: side = 60, blue: side = -60
//Left gear or right gear auto
void Autonomous::gearSide(int side)
{
	if(autoSteps == 0)
	{
		gyroDrive->straightDrive();
		isDriving = encDrive->setDistance(99.9);

		if(isDriving)
		{
			encDrive->reset();
			autoSteps = 1;
			isDriving = false;
		}
	}

	if(autoSteps == 1)
	{
		isTurning = gyroDrive->autoTurn(side, encDrive->averageEncoders());
		//drive->addOffset(encDrive->averageEncoders() * 0.001);

		if(isTurning)
		{
			encDrive->reset();
			gyroDrive->reset();
			autoSteps = 2;
			isTurning = false;
		}
	}

	if(autoSteps == 2)
	{
		time->Start();
		if(time->HasPeriodPassed(.5))
		{
			encDrive->reset();
			gyroDrive->reset();
			autoSteps = 3;
		}
	}

	if(autoSteps == 3)
	{
		time->Start();

		gyroDrive->straightDrive();
		isDriving = encDrive->setDistance(33.1);

		if(isDriving || time->HasPeriodPassed(2))
		{
			timerReset();
			encDrive->reset();
			autoSteps = 4;
			isDriving = false;
		}
	}

	if(autoSteps == 4)
	{

		isGears = true;
		gear->trapDoorOpen(true);

		if(isGears)
		{
			encDrive->reset();
			autoSteps = 5;
			isGears = false;
			isDriving = false;
		}
	}

	if(autoSteps == 5)
	{

		printf("\nStep 5 reached\n");
		gyroDrive->straightDrive();
		isDriving = encDrive->setDistance(-38);

		if(isDriving)
		{
			printf("\nStep 5 ended\n");
			gear->trapDoorClose(true);
			encDrive->reset();
			autoSteps = 6;
			isDriving = false;
		}
	}
}


void Autonomous::auto5(int nextStep)
{
	if(autoSteps == 20)
	{

		printf("Auto steps 20");
		gyroDrive->straightDrive();
		isDriving = encDrive->setDistance(-6);

		if(isDriving)
		{
			encDrive->reset();
			autoSteps = 21;
			isDriving = false;
		}
	}

	if(autoSteps == 21)
	{
		printf("Auto steps 21");
		gyroDrive->straightDrive();
		isDriving = encDrive->setDistance(15);

		if(isDriving)
		{
			encDrive->reset();
			autoSteps = nextStep;
			isDriving = false;
		}
	}
}

void Autonomous::timerReset()
{
	time->Stop();
	time->Reset();
}

void Autonomous::autoReset()
{
	autoSteps = 0;

	timerReset();

	isTurning = false;
	isDriving = false;
	isGears = false;
}
