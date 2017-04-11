#include "ClimbRope.h"

ClimbRope::ClimbRope(float speed) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	liftSpeed = speed;
	Requires(CommandBase::lift.get());
}

// Called just before this Command runs the first time
void ClimbRope::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void ClimbRope::Execute() {
	if(!IsFinished())
	{
		lift->setLiftMotor(liftSpeed);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool ClimbRope::IsFinished() {
	return lift->isLiftSwitchPressed() || !oi->getManipController()->GetRawButton(1);
}

// Called once after isFinished returns true
void ClimbRope::End() {
	lift->setLiftMotor(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ClimbRope::Interrupted() {
	End();
}
