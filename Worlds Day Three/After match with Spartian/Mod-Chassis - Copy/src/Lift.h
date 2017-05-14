/*
 * Lift.h
 *
 *  Created on: Jan 11, 2017
 *      Author: Admin
 */
#include "wpilib.h"
#include "CANTalon.h"

/*#ifndef SRC_LIFT_H_
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



#endif  SRC_LIFT_H_ */




#ifndef SRC_LIFT_H_
#define SRC_LIFT_H_

class Lift
{
public:
	Lift();
	~Lift();

	void liftRobot(bool button);
	bool beamOne();
	bool beamTwo();

	bool initialBreak();

	bool getLiftToggle();
	void resetLiftToggle();

	int getLiftStatus();
	CANTalon* leftCimMotor;

	void reset();

private:
	CANTalon* rightCimMotor;
	Timer* timeSpent;
	DigitalInput* liftStopOne;
	DigitalInput* liftStopTwo;

	bool initialBreakOne;
	bool initialBreakTwo;

	int liftStatus;

	bool liftToggle;

};



#endif /*SRC_LIFT_H_ */

