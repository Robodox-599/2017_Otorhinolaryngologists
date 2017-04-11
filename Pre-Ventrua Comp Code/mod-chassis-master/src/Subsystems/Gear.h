#ifndef Gear_H
#define Gear_H

#include <Commands/Subsystem.h>
#include "WPILib.h"

class Gear : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

	DoubleSolenoid* dustpan;
	DoubleSolenoid* trapdoor;

	DigitalInput* plateLeft;
	DigitalInput* plateRight;

public:
	Gear();
	void InitDefaultCommand();

	void dustpanDown();
	void dustpanUp();

	void trapdoorDown();
	void trapdoorUp();

	bool getTrapdoorPosition();	//true = UP false = DOWN
	bool getDustpanPosition();	//true = UP false = DOWN

	bool isPlatePressed();

};

#endif  // Gear_H
