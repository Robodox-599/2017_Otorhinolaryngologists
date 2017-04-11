#include "ShiftDriveGears.h"

ShiftDriveGears::ShiftDriveGears() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called once when the command executes
void ShiftDriveGears::Initialize() {
	if(CommandBase::driveBase->getShiftState())
	{
	  CommandBase::driveBase->shiftHighGear();
	}
	else
	{
	  CommandBase::driveBase->shiftLowGear();
	}
}
