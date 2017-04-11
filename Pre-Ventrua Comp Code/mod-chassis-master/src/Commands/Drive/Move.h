#ifndef Move_H
#define Move_H

#include "../../CommandBase.h"

class Move : public CommandBase {
public:
	Move(float leftSpeed, float rightSpeed, float seconds);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

	float speedL;
	float speedR;

};

#endif  // Move_H
