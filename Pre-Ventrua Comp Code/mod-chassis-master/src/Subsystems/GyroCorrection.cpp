#include "GyroCorrection.h"
#include "../RobotMap.h"

GyroCorrection::GyroCorrection() : Subsystem("ExampleSubsystem") {
	navX = new AHRS(SPI::Port::kMXP);
}

void GyroCorrection::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
