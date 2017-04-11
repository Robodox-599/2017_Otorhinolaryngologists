#ifndef OI_H
#define OI_H


#include "WPILib.h"


class OI {
private:
	XboxController* xbox;
	Joystick* atk3;

public:
	OI();

	XboxController* getDriveController();
	Joystick* getManipController();

};

#endif  // OI_H
