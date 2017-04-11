#ifndef ShiftDriveGears_H
#define ShiftDriveGears_H

#include "Commands/InstantCommand.h"
#include "../../CommandBase.h"

class ShiftDriveGears : public InstantCommand {
public:
	ShiftDriveGears();
	void Initialize();
};

#endif  // ShiftDriveGears_H
