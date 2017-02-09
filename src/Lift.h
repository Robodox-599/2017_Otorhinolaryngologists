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

	void liftRobot(bool override);
	
	void manualOverride(bool button);
	
	bool override;


private:
	CANTalon* leftCimMotor;
	CANTalon* rightCimMotor;
	Timer* timeSpent;

};



#endif /* SRC_LIFT_H_ */
