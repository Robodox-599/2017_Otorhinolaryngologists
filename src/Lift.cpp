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
	irBreakBeam1 = new DigitalInput(9);
	irBreakBeam2 = new DigitalInput(10);

}

Lift::~Lift()
{
	leftCimMotor = nullptr;
	rightCimMotor = nullptr;
	timeSpent = nullptr;
	irBreakBeam1 = nullptr;
	irBreakBeam2 = nullptr;
	delete leftCimMotor;
	delete rightCimMotor;
	delete timeSpent;
	delete irBreakBeam1;
	delete irBreakBeam2;
}


bool Lift::liftRobot(bool button)
{
	if(irBreakBeam1->Get() && irBreakBeam2->Get())
	{

		if ((button) || (leftCimMotor->GetOutputCurrent() < 2))
		{
			leftCimMotor->Set(0.75);
			rightCimMotor->Set(-0.75);
			timeSpent->Stop();
			timeSpent->Reset();
		}
		/* needed second parameter for counting how many times it has been broken
		bool broken = false;
		else if(irBreakBeam1->Get() && )
		{
			printf("status: %d", broken);
		}
		*/
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
	return false;
}



//testing code to see what values irBreakBeam will give...?


bool Lift::breakBeamTest()
{
	bool broken = false;

	if(irBreakBeam1->Get())
	{
		broken = true;
	}
	printf("status: %d", broken );
	return broken;
}



