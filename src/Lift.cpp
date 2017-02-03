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
	irBreakBeam = new DigitalOutput(9);

}

Lift::~Lift()
{
	leftCimMotor = nullptr;
	rightCimMotor = nullptr;
	timeSpent = nullptr;
	irBreakBeam = nullptr;
	delete leftCimMotor;
	delete rightCimMotor;
	delete timeSpent;
	delete irBreakBeam;
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


//replaced button with irBreakBeam

/*
void Lift::liftCimMotors()
{
	if ((irBreakBeam->Get()) || (leftCimMotor->GetOutputCurrent() < 2))
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
*/


//testing code to see what values irBreakBeam will give...?

/*
void Lift::liftCimMotors(bool broken)
{
	irBreakBeam->Get()
}
*/








