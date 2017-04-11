#include "MotionProfile.h"

MotionProfile::MotionProfile(float leftProfile[][3], float rightProfile[][3], double maxTime) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(CommandBase::driveBase.get());
    leftVelocity = leftProfile;
    rightVelocity = rightProfile;

    SetTimeout(maxTime);
}

// Called just before this Command runs the first time
void MotionProfile::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void MotionProfile::Execute() {
	int index = (int)(TimeSinceInitialized() / .1);
	
	driveBase->setRightSpeed(rightVelocity[index][1]);
	driveBase->setLeftSpeed(leftVelocity[index][1]);
}

// Make this return true when this Command no longer needs to run execute()
bool MotionProfile::IsFinished() {
	return IsTimedOut();
}

// Called once after isFinished returns true
void MotionProfile::End() {
	driveBase->setRightSpeed(0);
	driveBase->setLeftSpeed(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MotionProfile::Interrupted() {
	End();
}
