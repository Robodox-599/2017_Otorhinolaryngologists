#include "WPILib.h"

#include "Pixy.h"

class Robot: public IterativeRobot
{
private:
	LiveWindow *lw = LiveWindow::GetInstance();

	Pixy* pixy;
	XboxController* xbox;


	void RobotInit()
	{
		pixy = new Pixy();
		xbox = new XboxController(1);
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
		//Pixy Normal

		SmartDashboard::PutBoolean("Pixy Detected",pixy->Sensor->AddressOnly());

		if(pixy->updateBuffer()){

			SmartDashboard::PutNumber("Check Sum", pixy->get());
			SmartDashboard::PutNumber("Signature", pixy->get());
			SmartDashboard::PutNumber("X Center", pixy->get());
			SmartDashboard::PutNumber("Y Center", pixy->get());
			SmartDashboard::PutNumber("Width", pixy->get());
			SmartDashboard::PutNumber("Height", pixy->get());

		}



	}

	void TestPeriodic()
	{
		lw->Run();
	}
};

START_ROBOT_CLASS(Robot)
