#ifndef ClimbPause_H
#define ClimbPause_H

#include "../../CommandBase.h"

class ClimbPause : public CommandBase {
public:
	ClimbPause();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // ClimbPause_H
