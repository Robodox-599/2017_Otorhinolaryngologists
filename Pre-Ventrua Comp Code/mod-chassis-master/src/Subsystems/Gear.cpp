#include "Gear.h"
#include "../RobotMap.h"

Gear::Gear() : Subsystem("Gear") {
	dustpan = new DoubleSolenoid(1,3);//DUSTPAN_PORT_A, DUSTPAN_PORT_B);
	trapdoor = new DoubleSolenoid(TRAPDOOR_PORT_A, TRAPDOOR_PORT_B);

	plateLeft = new DigitalInput(LEFT_PLATE_PORT);
	plateRight = new DigitalInput(RIGHT_PLATE_PORT);
}

void Gear::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void Gear::dustpanDown()
{
	dustpan->Set(DoubleSolenoid::kReverse);
}

void Gear::dustpanUp()
{
	dustpan->Set(DoubleSolenoid::kForward);
}

void Gear::trapdoorDown()
{
	trapdoor->Set(DoubleSolenoid::kReverse);
}

void Gear::trapdoorUp()
{
	trapdoor->Set(DoubleSolenoid::kForward);
}

bool Gear::getDustpanPosition()
{
	if(dustpan->Get() == DoubleSolenoid::kForward)
	{
		return true;
	}
	return false;
}

bool Gear::getTrapdoorPosition()
{
	if(dustpan->Get() == DoubleSolenoid::kForward)
	{
		return true;
	}
	return false;
}

bool Gear::isPlatePressed()
{
	if(plateLeft->Get() || plateRight->Get())
	{
		return true;
	}

	return false;
}
