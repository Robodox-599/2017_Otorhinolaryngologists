/*
 * Gears.cpp
 *
 *  Created on: Jan 11, 2017
 *      Author: Admin
 */
#include "Gears.h"

Gears::Gears()
{
	intakeRotatorSol = new DoubleSolenoid(0, 1);
	trapDoorSol = new DoubleSolenoid(2, 3);
	pressurePlate = new DigitalInput(0);
	trapDoorSol->Set(DoubleSolenoid::Value::kForward);
	timeSpent = new Timer();
	retracted = true;
	comp599 = new Compressor();

	comp599->SetClosedLoopControl(true);
}



Gears::~Gears()
{
	delete intakeRotatorSol;
	delete trapDoorSol;
	delete pressurePlate;
	delete timeSpent;

	intakeRotatorSol = nullptr;
	trapDoorSol = nullptr;
	pressurePlate = nullptr;
	timeSpent = nullptr;
}


void Gears::intakeRotator(bool rotate, bool two)
{
	if(rotate)//&& retracted)
	{
		intakeRotatorSol->Set(DoubleSolenoid::Value::kForward);
		retracted = false;
		//Wait(0.5);
	}
	else if(two)
	{
		intakeRotatorSol->Set(DoubleSolenoid::Value::kReverse);
		retracted = true;
	}
}

/* hhhhhhhh
 *
 */
void Gears::trapDoor()
{

	//printf("test \n");
	if(pressurePlate->Get())
	{
		printf("test inside if \n");
		trapDoorSol->Set(DoubleSolenoid::Value::kReverse);
		timeSpent->Start();

	}
	else if(timeSpent->HasPeriodPassed(5))
	{
		timeSpent->Stop();
		timeSpent->Reset();
		trapDoorSol->Set(DoubleSolenoid::Value::kForward);
	}
}
