#include "ToggleDustpan.h"

ToggleDustpan::ToggleDustpan() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called once when the command executes
void ToggleDustpan::Initialize() {
	if(CommandBase::gear->getDustpanPosition())
	{
		CommandBase::gear->dustpanDown();
	}
	else
	{
		CommandBase::gear->dustpanUp();
	}
}
