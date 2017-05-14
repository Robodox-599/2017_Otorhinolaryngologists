/*
 * Gears.cpp
 *
 *  Created on: Jan 11, 2017
 *      Author: Admin
 */
#include "Gears.h"
#include "WPILib.h"
Gears::Gears()
{
	intakeRotatorSol = new DoubleSolenoid(2,3);
	trapDoorSol = new DoubleSolenoid(4,5);

	plateOne = new DigitalInput(4);

	trapDoorSol->Set(DoubleSolenoid::Value::kForward);
	timeSpent = new Timer();
	rState = true;
	tdState = false;
}



Gears::~Gears()
{
	delete intakeRotatorSol;
	delete trapDoorSol;
	delete plateOne;
	delete timeSpent;

	intakeRotatorSol = nullptr;
	trapDoorSol = nullptr;
	plateOne = nullptr;
	timeSpent = nullptr;
}


void Gears::intakeRotator(bool rotate)
{
	if(rotate && rState)
	{
		if(intakeRotatorSol->Get() == DoubleSolenoid::Value::kForward)
		{
			intakeRotatorSol->Set(DoubleSolenoid::Value::kReverse);
		}
		else
		{
			intakeRotatorSol->Set(DoubleSolenoid::Value::kForward);
		}
		rState = false;
	}

	if(!rotate && !rState)
	{
		rState = true;
	}
}

/*bool Gears::trapDoor()
{
	if(plateOne->Get())//debounce
	{
		timeSpent->Start();
		trapDoorSol->Set(DoubleSolenoid::Value::kReverse);
		return true;
	}
	else if(timeSpent->HasPeriodPassed(3))
	{
		timeSpent->Stop();
		timeSpent->Reset();
		trapDoorSol->Set(DoubleSolenoid::Value::kForward);
	}

	return false;
}*/

void Gears::trapDoorOpen(bool open)
{
	if(open)
	{
		printf("release gear");
		trapDoorSol->Set(DoubleSolenoid::Value::kReverse);
	}
}

void Gears::trapDoorClose(bool close)
{
	if(close)
	{
		trapDoorSol->Set(DoubleSolenoid::Value::kForward);
	}
}

bool Gears::getPressurePlateStatus()
{
	if(plateOne->Get()) //|| plateTwo->Get())
	{
		return false;
	}

	return true;
}


bool Gears::getPlateOne()
{
	return plateOne->Get();
}

string Gears::trapDoorState()
{
	if(trapDoorSol->Get() == DoubleSolenoid::Value::kForward)
	{
		return "Closed";
	}

	return "Open";
}

string Gears::rotatorState()
{
	if(intakeRotatorSol->Get() == DoubleSolenoid::Value::kForward)
	{
		return "Open";
	}

	return "Closed";
}
