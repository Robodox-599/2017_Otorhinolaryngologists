#include "WPILib.h"
#include "Drive.h"
#include "Pixy.h"

class Robot: public IterativeRobot
{
private:
	LiveWindow *lw = LiveWindow::GetInstance();

	Drive* drive;
	Pixy* pixy;
	XboxController* xbox;


	void RobotInit()
	{
		drive = new Drive();
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
		/*
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

		*/


		drive->drive(xbox->GetX(XboxController::kRightHand), xbox->GetX(XboxController::kLeftHand));

		if(xbox->GetAButton())
		{
			drive->setAutoTurning(90);
		}

		/*
		//Drive code
		drive->drive(xbox->GetRawAxis(4), xbox->GetRawAxis(1));
		if(xbox->GetRawButton(1))
		{
			xbox->SetRumble(Joystick::RumbleType::kLeftRumble, .5);
			xbox->SetRumble(Joystick::RumbleType::kRightRumble, .5);
		}
		else
		{
			xbox->SetRumble(Joystick::RumbleType::kLeftRumble, 0);
			xbox->SetRumble(Joystick::RumbleType::kRightRumble, 0);
		}

		SmartDashboard::PutNumber("Front Right", drive->frontRightDrive->Get());
		SmartDashboard::PutNumber("Back Right", drive->backRightDrive->Get());
		SmartDashboard::PutNumber("Front Left", drive->frontLeftDrive->Get());
		SmartDashboard::PutNumber("Back Left", drive->backLeftDrive->Get());

		SmartDashboard::PutNumber("Yaw from Gyro", drive->navX->GetYaw());
		SmartDashboard::PutNumber("Error", drive->error);

		*/

	}

	void TestPeriodic()
	{
		lw->Run();
	}
};

START_ROBOT_CLASS(Robot)
