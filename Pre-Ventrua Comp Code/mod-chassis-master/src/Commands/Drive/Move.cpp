#include "Move.h"

Move::Move(float leftSpeed, float rightSpeed, float seconds) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(CommandBase::driveBase.get());
	SetTimeout(seconds);

	speedL = leftSpeed;
	speedR = rightSpeed;

}

// Called just before this Command runs the first time
void Move::Initialize() {
	driveBase->setLeftSpeed(speedL);
	driveBase->setRightSpeed(speedR);
}

// Called repeatedly when this Command is scheduled to run
void Move::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool Move::IsFinished() {
	return IsTimedOut();
}

// Called once after isFinished returns true
void Move::End() {
	driveBase->setLeftSpeed(0);
	driveBase->setRightSpeed(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Move::Interrupted() {
	End();
}
