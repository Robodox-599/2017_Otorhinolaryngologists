#include "CommandBase.h"

#include <Commands/Scheduler.h>

// Initialize a single static instance of all of your subsystems. The following
// line should be repeated for each subsystem in the project.
//std::unique_ptr<DriveBase> CommandBase::exampleSubsystem = std::make_unique<DriveBase>();

std::unique_ptr<DriveBase> CommandBase::driveBase = std::make_unique<DriveBase>();
std::unique_ptr<Lift> CommandBase::lift = std::make_unique<Lift>();
std::unique_ptr<Gear> CommandBase::gear = std::make_unique<Gear>();
std::unique_ptr<OI> CommandBase::oi = std::make_unique<OI>();

CommandBase::CommandBase(const std::string &name) :frc::Command(name) {

}

/*void CommandBase::init()
{
	CommandBase::driveBase = new DriveBase();
	CommandBase::oi = new OI();
	CommandBase::gear = new Gear();
	CommandBase::lift = new Lift();
	//CommandBase::gyroCorrection = new GyroCorrection();
}*/
