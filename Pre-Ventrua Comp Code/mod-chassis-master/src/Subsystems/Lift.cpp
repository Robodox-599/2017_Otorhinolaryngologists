#include "Lift.h"
#include "../RobotMap.h"

Lift::Lift() : Subsystem("Lift") {
	leftLiftMotor = new CANTalon(LEFT_LIFT_MOTOR_PORT);
	rightLiftMotor = new CANTalon(RIGHT_LIFT_MOTOR_PORT);

	leftLiftSwitch = new DigitalInput(LEFT_LIFT_SWITCH_PORT);
	rightLiftSwitch = new DigitalInput(RIGHT_LIFT_SWITCH_PORT);

	leftLiftMotor->SetControlMode(CANTalon::ControlMode::kFollower);
	leftLiftMotor->SetInverted(true); //TODO: check if this is the correct function to use
	leftLiftMotor->Set(RIGHT_LIFT_MOTOR_PORT);
}

void Lift::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void Lift::setLiftMotor(float speed)
{
	rightLiftMotor->Set(speed);
}

bool Lift::isLiftSwitchPressed()
{
	if(leftLiftSwitch->Get() || rightLiftSwitch->Get())
	{
		return true;
	}

	return false;
}
