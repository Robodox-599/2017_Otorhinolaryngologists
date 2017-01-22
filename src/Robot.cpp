#include "WPILib.h"

#include "Pixy.h"

class Robot: public IterativeRobot
{
private:
	LiveWindow *lw = LiveWindow::GetInstance();

	Pixy* pixy;

	void RobotInit()
	{
		pixy = new Pixy();
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
		if(pixy->updateBuffer())
		{
			SmartDashboard::PutNumber("Check Sum", pixy->convert(0,1));
			SmartDashboard::PutNumber("Signature", pixy->convert(2,3));
			SmartDashboard::PutNumber("X Center", pixy->convert(4,5));
			SmartDashboard::PutNumber("Y Center", pixy->convert(6,7));
			SmartDashboard::PutNumber("Width", pixy->convert(8,9));
			SmartDashboard::PutNumber("Height", pixy->convert(10,11));
		}
	}

	void TestPeriodic()
	{
		lw->Run();
	}
};

START_ROBOT_CLASS(Robot)
