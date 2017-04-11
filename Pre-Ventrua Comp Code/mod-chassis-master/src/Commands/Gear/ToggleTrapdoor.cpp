#include "ToggleTrapdoor.h"

ToggleTrapdoor::ToggleTrapdoor() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called once when the command executes
void ToggleTrapdoor::Initialize() {
	if(CommandBase::gear->getTrapdoorPosition())
	{
		CommandBase::gear->trapdoorDown();
	}
	else
	{
		CommandBase::gear->trapdoorUp();
	}
}
