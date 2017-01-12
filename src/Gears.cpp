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
}



Gears::~Gears()
{
	delete intakeRotatorSol;
	delete trapDoorSol;
	delete pressurePlate;

	intakeRotatorSol = nullptr;
	trapDoorSol = nullptr;
	pressurePlate = nullptr;
}


void Gears::intakeRotator(bool rotate)
{
	if(rotate)
	{
		intakeRotatorSol->Set(DoubleSolenoid::Value::kForward);
		Wait(5);
		intakeRotatorSol->Set(DoubleSolenoid::Value::kReverse);
	}

}


void Gears::trapDoor(bool retract)
{
	if(pressurePlate->Get())
	{
		trapDoorSol->Set(DoubleSolenoid::Value::kReverse);
	}
	else
	{
		Wait(2);
		trapDoorSol->Set(DoubleSolenoid::Value::kForward);
	}
}




