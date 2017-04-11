#ifndef ClimbRope_H
#define ClimbRope_H

#include "../../CommandBase.h"

class ClimbRope : public CommandBase {
public:
	ClimbRope(float speed);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

	float liftSpeed;
};

#endif  // ClimbRope_H
