#define OLD_LIFT_CODE

#ifdef NEW_LIFT_CODE
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

	override = false;

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



void Lift::liftRobot(bool override)
{

	if (!override)
	{
		if (leftCimMotor->GetOutputCurrent() < 2)
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
}

void Lift::manualOverride(bool button)
{
	if (button)
	{
		override = true;
	}

	else if(override)
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
#endif /*NEW_LIFT_CODE*/

































#ifdef OLD_LIFT_CODE
/*
 * Lift.cpp
 *
 *  Created on: Jan 11, 2017
 *      Author: Admin
 */
#include "Lift.h"

Lift::Lift()
{
	leftCimMotor = new CANTalon(5);
	rightCimMotor = new CANTalon(6);

	liftStopOne = new DigitalInput(3);
	liftStopTwo = new DigitalInput(7);

	timeSpent = new Timer();

	initialBreakOne = false;
	initialBreakTwo = false;

	liftStatus = 0;

	liftToggle = false;

	leftCimMotor->SetEncPosition(0);
}

Lift::~Lift()
{
	leftCimMotor = nullptr;
	rightCimMotor = nullptr;
	timeSpent = nullptr;
	liftStopOne = nullptr;
	liftStopTwo = nullptr;
	delete leftCimMotor;
	delete rightCimMotor;
	delete timeSpent;
	delete liftStopOne;
	delete liftStopTwo;
}

/*
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
}*/


void Lift::liftRobot(bool button)
{
	/*if(liftStatus == 0 && button)
	{
		leftCimMotor->Set(0.75);
		rightCimMotor->Set(-0.75);
		if(liftStopOne->Get() || liftStopTwo->Get())
		{
			liftStatus = 1;
		}
	}
	else if(liftStatus == 1)
	{
		leftCimMotor->Set(0);
		rightCimMotor->Set(0);
		liftStatus = 2;
	}
	else if(liftStatus == 2 && button)
	{
		leftCimMotor->Set(0.75);
		rightCimMotor->Set(-0.75);
	}
	else
	{
		leftCimMotor->Set(0);
		rightCimMotor->Set(0);
	}*/




	/*if(leftCimMotor->GetEncPosition() > 18432)
	{*/
		if(button && liftStatus == 0)
		{
			if(liftStopOne->Get() || liftStopTwo->Get())//was or changed 2/15/2017
			{
				//leftCimMotor->Set(0);
				//rightCimMotor->Set(0);
				//liftStatus = 1;


				timeSpent->Start();
				if(timeSpent->HasPeriodPassed(0))
				{
					leftCimMotor->Set(0);
					rightCimMotor->Set(0);
					liftStatus = 1;
				}
			}
			else
			{

				timeSpent->Stop();
				timeSpent->Reset();


				leftCimMotor->Set(0.75);
				rightCimMotor->Set(-0.75);
				liftToggle = true;
			}
		}
		else if(liftStatus == 0)
		{
			leftCimMotor->Set(0);
			rightCimMotor->Set(0);
		}
		else if(!button && liftStatus == 1)
		{
			leftCimMotor->Set(0);
			rightCimMotor->Set(0);
			liftStatus = 2;
		}
		else if(button && liftStatus == 2)
		{
			leftCimMotor->Set(0.75);
			rightCimMotor->Set(-0.75);
			liftStatus = 3;
		}
		else if(!button && liftStatus == 3)
		{
			leftCimMotor->Set(0);
			rightCimMotor->Set(0);
			liftStatus = 0;
		}
	/*}
	else if(button)
	{
		leftCimMotor->Set(0.75);
		rightCimMotor->Set(-0.75);
	}
	else
	{
		leftCimMotor->Set(0);
		rightCimMotor->Set(0);
	}*/
}


//testing code to see what values irBreakBeam will give...?


bool Lift::beamOne()
{
	if(liftStopOne->Get())
	{
		initialBreakOne = true;
	}

	return liftStopOne->Get();
}

bool Lift::beamTwo()
{
	if(liftStopTwo->Get())
	{
		initialBreakTwo = true;
	}

	return liftStopTwo->Get();
}


bool Lift::initialBreak()
{
	if(initialBreakOne && initialBreakTwo)
	{
		return true;
	}

	return false;
}

bool Lift::getLiftToggle()
{
	return liftToggle;
}

void Lift::resetLiftToggle()
{
	liftToggle = false;
}

int Lift::getLiftStatus()
{
	return liftStatus;
}

void Lift::reset()
{
	leftCimMotor->SetEncPosition(0);

}

#endif /*OLD_LIFT_CODE*/

