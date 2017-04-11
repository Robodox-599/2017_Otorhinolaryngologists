#ifndef ToggleTrapdoor_H
#define ToggleTrapdoor_H

#include "Commands/InstantCommand.h"
#include "../../CommandBase.h"

class ToggleTrapdoor : public InstantCommand {
public:
	ToggleTrapdoor();
	void Initialize();
};

#endif  // ToggleTrapdoor_H
