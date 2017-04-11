#ifndef Lift_H
#define Lift_H

#include <Commands/Subsystem.h>
#include "CANTalon.h"
#include "WPILib.h"

class Lift : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

	CANTalon* leftLiftMotor;
	CANTalon* rightLiftMotor;

	DigitalInput* leftLiftSwitch;
	DigitalInput* rightLiftSwitch;

public:
	Lift();
	void InitDefaultCommand();

	void setLiftMotor(float speed);

	bool isLiftSwitchPressed();
};

#endif  // Lift_H
