/*
 * Lift.h
 *
 *  Created on: Jan 11, 2017
 *      Author: Admin
 */
#include "wpilib.h"

#ifndef SRC_LIFT_H_
#define SRC_LIFT_H_

class Lift
{
public:
	Lift();
	~Lift();

	void liftCimMotors();

private:
	CANTalon* leftCimMotor;
	CANTalon* rightCimMotor;
	Timer* timeSpent;
	DigitalOutput* irBreakBeam;

};



#endif /* SRC_LIFT_H_ */
