#include "DriveBase.h"
#include "../RobotMap.h"

DriveBase::DriveBase() : Subsystem("DriveBase") {
	frontLeftDrive = new CANTalon(FRONT_LEFT_DRIVE_PORT);
	backLeftDrive = new CANTalon(BACK_LEFT_DRIVE_PORT);
	frontRightDrive = new CANTalon(FRONT_RIGHT_DRIVE_PORT);
	backRightDrive = new CANTalon(BACK_RIGHT_DRIVE_PORT);

	shifter = new DoubleSolenoid(0,1);

	frontLeftDrive->SetTalonControlMode(CANTalon::TalonControlMode::kSpeedMode);
	frontLeftDrive->SetFeedbackDevice(CANTalon::FeedbackDevice::QuadEncoder);
	backLeftDrive->SetTalonControlMode(CANTalon::TalonControlMode::kFollowerMode);
	backLeftDrive->Set(FRONT_LEFT_DRIVE_PORT);


	frontRightDrive->SetTalonControlMode(CANTalon::TalonControlMode::kSpeedMode);
	frontRightDrive->SetFeedbackDevice(CANTalon::FeedbackDevice::QuadEncoder);
	backRightDrive->SetTalonControlMode(CANTalon::TalonControlMode::kFollowerMode);
	backRightDrive->Set(FRONT_RIGHT_DRIVE_PORT);
}

void DriveBase::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());

	SetDefaultCommand(new JoystickDrive());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void DriveBase::setLeftSpeed(float speed)
{
	frontLeftDrive->Set(speed*1024.0/600.0);//(speed * 1024.0)/(60 * 10));//rev/1min to tics/100ms
	SmartDashboard::PutNumber("Command: ", speed*1024.0/600.0);
}

void DriveBase::setRightSpeed(float speed)
{
	frontRightDrive->Set(speed*1024.0/600.0);//(speed * 1024.0)/(60 * 10));//rev/1min to tics/100ms
	SmartDashboard::PutNumber("Command: ", speed*1024.0/600.0);
}

int DriveBase::getLeftSpeed()
{
	SmartDashboard::PutNumber("RPM Left: ", frontLeftDrive->GetEncVel()*600.0/1024);
	SmartDashboard::PutNumber("Raw Value Left: ", frontLeftDrive->GetEncVel());
	SmartDashboard::PutNumber("error Left: ", frontLeftDrive->GetClosedLoopError());

	return frontLeftDrive->GetSpeed();
}

int DriveBase::getRightSpeed()
{
	SmartDashboard::PutNumber("RPM Right: ", frontLeftDrive->GetEncVel()*600.0/1024);
	SmartDashboard::PutNumber("Raw Value Right: ", frontLeftDrive->GetEncVel());
	SmartDashboard::PutNumber("error Right: ", frontLeftDrive->GetClosedLoopError());

	return frontRightDrive->GetEncVel();
}

//TODO: make sure this is correct position for high gear
void DriveBase::shiftHighGear()
{
  shifter->Set(DoubleSolenoid::kReverse);
}

//TODO: make sure this is correct position for low gear
void DriveBase::shiftLowGear()
{
  shifter->Set(DoubleSolenoid::kForward);
}

//TODO: make sure to change this
bool DriveBase::getShiftState()
{
  if(shifter->Get() == DoubleSolenoid::kForward)
  {
    return true;
  }
  return false;
}









