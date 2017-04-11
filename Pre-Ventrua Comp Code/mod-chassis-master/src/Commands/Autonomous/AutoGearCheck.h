#ifndef AutoGearCheck_H
#define AutoGearCheck_H

#include "../../CommandBase.h"

class AutoGearCheck : public CommandBase {
public:
	AutoGearCheck();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // AutoGearCheck_H
