/*
 * Lift.h
 *
 *  Created on: Jan 11, 2017
 *      Author: Admin
 */
#include "wpilib.h"
#include "CANTalon.h"


#ifndef SRC_LIFT_H_
#define SRC_LIFT_H_

class Lift
{
public:
	Lift();
	~Lift();

	void liftRobot(bool button);
	bool breakBeamTest();

private:
	CANTalon* leftCimMotor;
	CANTalon* rightCimMotor;
	Timer* timeSpent;
	DigitalOutput* irBreakBeam;

};



#endif /* SRC_LIFT_H_ */
