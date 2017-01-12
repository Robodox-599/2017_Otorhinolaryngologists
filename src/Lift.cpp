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
}

Lift::~Lift()
{
	leftCimMotor = nullptr;
	rightCimMotor = nullptr;
	delete leftCimMotor;
	delete rightCimMotor;
}

void Lift::liftCimMotors(float speed)
{
	if (speed > 0.3 || speed <-0.3)
	{
		leftCimMotor->Set(speed);
		rightCimMotor->Set(speed);
	}
	else
	{
		leftCimMotor->Set(0);
		rightCimMotor->Set(0);
	}
}

