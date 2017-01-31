#include "WPILib.h"
#include "Commands/Command.h"
#include "Gears.h"

class Robot: public IterativeRobot
{
private:
	Gears* gear;
	XboxController* xbox;

	void RobotInit()
	{
		gear = new Gears();
		xbox = new XboxController(0);
	}

	/**
     * This function is called once each time the robot enters Disabled mode.
     * You can use it to reset any subsystem information you want to clear when
	 * the robot is disabled.
     */
	void DisabledInit()
	{
	}

	void DisabledPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}


	void AutonomousInit()
	{

	}

	void AutonomousPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void TeleopInit()
	{

	}

	void TeleopPeriodic()
	{
		Scheduler::GetInstance()->Run();
		gear->intakeRotator(xbox->GetAButton(), xbox->GetBButton());
		//printf("test robot file \n");
		gear->trapDoor(xbox->GetYButton());
	}

	void TestPeriodic()
	{
		LiveWindow::GetInstance()->Run();
	}
};

START_ROBOT_CLASS(Robot)

