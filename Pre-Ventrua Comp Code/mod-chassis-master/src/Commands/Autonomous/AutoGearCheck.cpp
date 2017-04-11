#include "AutoGearCheck.h"

AutoGearCheck::AutoGearCheck() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void AutoGearCheck::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void AutoGearCheck::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool AutoGearCheck::IsFinished() {
	return gear->isPlatePressed();
}

// Called once after isFinished returns true
void AutoGearCheck::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoGearCheck::Interrupted() {

}
