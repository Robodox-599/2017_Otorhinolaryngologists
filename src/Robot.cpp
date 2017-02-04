#include "WPILib.h"
#include "Lift.cpp"

class Robot: public IterativeRobot
{
private:
	LiveWindow *lw = LiveWindow::GetInstance();
	Joystick* ATK3;
	Lift* lift;

	void RobotInit()
	{
		ATK3 = new Joystick(0);
		lift = new Lift();
	}

	void AutonomousInit()
	{

	}

	void AutonomousPeriodic()
	{

	}

	void TeleopInit()
	{

	}

	void TeleopPeriodic()
	{
		lift->liftRobot(ATK3->GetY());


		SmartDashboard::PutBoolean("Break Beam Status: ", lift->irBreakBeam->Get());

	}

	void TestPeriodic()
	{
		lw->Run();
	}


};

START_ROBOT_CLASS(Robot)
