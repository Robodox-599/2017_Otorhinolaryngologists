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
			SmartDashboard::PutNumber("Check Sum", pixy->getValue(Pixy::Value::CHECKSUM));
			SmartDashboard::PutNumber("Signature", pixy->getValue(Pixy::Value::SIGNATURE));
			SmartDashboard::PutNumber("X Center", pixy->getValue(Pixy::Value::X_CENTER));
			SmartDashboard::PutNumber("Y Center", pixy->getValue(Pixy::Value::Y_CENTER));
			SmartDashboard::PutNumber("Width", pixy->getValue(Pixy::Value::WIDTH));
			SmartDashboard::PutNumber("Height", pixy->getValue(Pixy::Value::HEIGHT));
		}
	}

	void TestPeriodic()
	{
		lw->Run();
	}
};

START_ROBOT_CLASS(Robot)
