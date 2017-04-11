#ifndef ToggleDustpan_H
#define ToggleDustpan_H

#include "Commands/InstantCommand.h"
#include "../../CommandBase.h"

class ToggleDustpan : public InstantCommand {
public:
	ToggleDustpan();
	void Initialize();
};

#endif  // ToggleDustpan_H
