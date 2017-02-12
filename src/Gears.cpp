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

	plateOne = new DigitalInput(0);
	plateTwo = new DigitalInput(4);

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
	delete plateTwo;
	delete timeSpent;

	intakeRotatorSol = nullptr;
	trapDoorSol = nullptr;
	plateOne = nullptr;
	plateTwo = nullptr;
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

bool Gears::trapDoor()
{
	if(!plateOne->Get() || plateTwo->Get())//debounce
	{
		timeSpent->Start();
		if(timeSpent->HasPeriodPassed(.2)) //&& (!plateOne->Get() || plateTwo->Get()))//trapDoorSol->Get() == DoubleSolenoid::Value::kReverse && !timeSpent->HasPeriodPassed(3)
		{
			timeSpent->Reset();
			//timeSpent->Start();
			trapDoorSol->Set(DoubleSolenoid::Value::kReverse);
			return true;
		}
	}
	else if(timeSpent->HasPeriodPassed(3))
	{
		timeSpent->Stop();
		timeSpent->Reset();
		trapDoorSol->Set(DoubleSolenoid::Value::kForward);
	}
	/*else if(!timeSpent->HasPeriodPassed(.2))
	{
		timeSpent->Stop();
		timeSpent->Reset();
	}*/

	return false;
}

/*void Gears::intakeRotator(bool rotate)
{
	if(rotate && retracted)
	{
		intakeRotatorSol->Set(DoubleSolenoid::Value::kForward);
		rState = false;
		Wait(0.5);
	}
	else if(rotate)
	{
		intakeRotatorSol->Set(DoubleSolenoid::Value::kReverse);
		rState = true;
	}
}*/


void Gears::toggleTrapDoor(bool open)
{
	if(open && tdState)
	{
		if(trapDoorSol->Get() == DoubleSolenoid::Value::kForward)
		{
			trapDoorSol->Set(DoubleSolenoid::Value::kReverse);
		}
		else
		{
			trapDoorSol->Set(DoubleSolenoid::Value::kForward);
		}
		tdState = false;
	}

	if(!open && !tdState)
	{
		tdState = true;
	}
}


/*
if(rotate && retracted)
{
	if(intakeRotatorSol->Get() == DoubleSolenoid::Value::kForward)
	{
		intakeRotatorSol->Set(DoubleSolenoid::Value::kReverse);
	}
	else
	{
		intakeRotatorSol->Set(DoubleSolenoid::Value::kForward);
	}
	retracted = false;
}

if(!rotate && !retracted)
{
	retracted = true;
}
 * */

/*
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
*/

bool Gears::getPressurePlateStatus()
{
	if(!plateOne->Get() || plateTwo->Get())
	{
		return true;
	}

	return false;
}


bool Gears::getPlateOne()
{
	return !plateOne->Get();
}

bool Gears::getPlateTwo()
{
	return plateTwo->Get();
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
