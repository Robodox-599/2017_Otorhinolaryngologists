#ifndef MotionProfile_H
#define MotionProfile_H

#include <array>

#include "../../CommandBase.h"

using namespace std;
class MotionProfile : public CommandBase {
public:
	MotionProfile(float leftProfile[][3], float rightProfile[][3], double maxTime);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

    float leftVelocity[][];
    float rightVelocity[][];
};

#endif  // MotionProfile_H
