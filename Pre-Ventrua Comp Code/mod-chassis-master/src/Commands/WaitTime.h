#ifndef WaitTime_H
#define WaitTime_H

#include "../CommandBase.h"

class WaitTime : public CommandBase {
public:
	WaitTime(float seconds);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // WaitTime_H
