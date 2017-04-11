#include "JoystickDrive.h"

JoystickDrive::JoystickDrive() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());

	leftSpeed = 0;
	rightSpeed = 0;

	Requires(CommandBase::driveBase.get());


}

// Called just before this Command runs the first time
void JoystickDrive::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void JoystickDrive::Execute() {
	leftSpeed = oi->getDriveController()->GetY(XboxController::kLeftHand);
	rightSpeed = oi->getDriveController()->GetY(XboxController::kRightHand);

	if(leftSpeed > DRIVE_DEADZONE || leftSpeed < -DRIVE_DEADZONE)
	{
		driveBase->setLeftSpeed(leftSpeed);
	}
	else
	{
		driveBase->setLeftSpeed(0);
	}

	if(rightSpeed > DRIVE_DEADZONE || rightSpeed < -DRIVE_DEADZONE)
	{
		driveBase->setRightSpeed(rightSpeed);
	}
	else
	{
		driveBase->setRightSpeed(0);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool JoystickDrive::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void JoystickDrive::End() {
	driveBase->setRightSpeed(0);
	driveBase->setLeftSpeed(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void JoystickDrive::Interrupted() {
	End();
}
