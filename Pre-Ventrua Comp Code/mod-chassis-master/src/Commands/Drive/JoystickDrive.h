#ifndef JoystickDrive_H
#define JoystickDrive_H

#include "../../CommandBase.h"


class JoystickDrive : public CommandBase {
public:
	JoystickDrive();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

	float leftSpeed;
	float rightSpeed;
};

#endif  // JoystickDrive_H
