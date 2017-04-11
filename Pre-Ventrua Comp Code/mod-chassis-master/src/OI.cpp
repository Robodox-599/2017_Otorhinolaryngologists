#include "OI.h"

OI::OI() {
	// Process operator interface input here.
	xbox = new XboxController(0);
	atk3 = new Joystick(1);
}

Joystick* OI::getManipController()
{
	return atk3;
}

XboxController* OI::getDriveController()
{
	return xbox;
}
