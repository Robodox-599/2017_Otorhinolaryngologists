/*
 * Gears.cpp
 *
 *  Created on: Jan 11, 2017
 *      Author: Admin
 */
#include "Gears.h"

Gears::Gears()
{
	intakeRotatorSol = new DoubleSolenoid(3, 4);
	trapDoorSol = new DoubleSolenoid(1, 2);
	pressurePlate = new DigitalInput(1);
	trapDoorSol->Set(DoubleSolenoid::Value::kForward);
	timeSpent = new Timer();
	retracted = true;
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


void Gears::intakeRotator(bool rotate)
{
	if(rotate && retracted)
	{
		intakeRotatorSol->Set(DoubleSolenoid::Value::kForward);
		retracted = false;
		Wait(0.5);
	}
	else if(rotate)
	{
		intakeRotatorSol->Set(DoubleSolenoid::Value::kReverse);
		retracted = true;
	}
}

bool Gears::trapDoor()
{
	if(pressurePlate->Get())
	{
		timeSpent->Start();
		trapDoorSol->Set(DoubleSolenoid::Value::kReverse);
		return true;
	}
	else if(timeSpent->HasPeriodPassed(5))
	{
		timeSpent->Stop();
		timeSpent->Reset();
		trapDoorSol->Set(DoubleSolenoid::Value::kForward);
	}
	return false;
}
