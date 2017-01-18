/*
 * Lift.cpp
 *
 *  Created on: Jan 11, 2017
 *      Author: Admin
 */
#include "Lift.h"

Lift::Lift()
{
	leftCimMotor = new CANTalon(7);
	rightCimMotor = new CANTalon(8);
	timeSpent = new Timer();
}

Lift::~Lift()
{
	leftCimMotor = nullptr;
	rightCimMotor = nullptr;
	timeSpent = nullptr;
	delete leftCimMotor;
	delete rightCimMotor;
	delete timeSpent;
}

void Lift::liftCimMotors(bool button)
{
	if ((button) || (leftCimMotor->GetOutputCurrent() < 2))
	{
		leftCimMotor->Set(0.75);
		rightCimMotor->Set(-0.75);
		timeSpent->Stop();
		timeSpent->Reset();
	}
	else
	{
		timeSpent->Start();
		if (timeSpent->HasPeriodPassed(1) || !button)
		{
			leftCimMotor->Set(0);
			rightCimMotor->Set(0);
		}
	}
}

void Lift::runMotors(bool button)
{
	if (button)
	{
		leftCimMotor->Set(0.75);
		rightCimMotor->Set(-0.75);
	}
	else
	{
		leftCimMotor->Set(0);
		rightCimMotor->Set(0);
	}
}





