#include "WPILib.h"
#include "Drive.h"
#include "Pixy.h"
class Robot: public IterativeRobot
{
private:
	LiveWindow *lw = LiveWindow::GetInstance();

	Drive* drive;
	Pixy* pixy;
	Joystick* xbox;


	void RobotInit()
	{
		drive = new Drive();
		pixy = new Pixy();
		xbox = new Joystick(1);
	}


	/**
	 * This autonomous (along with the chooser code above) shows how to select between different autonomous modes
	 * using the dashboard. The sendable chooser code works with the Java SmartDashboard. If you prefer the LabVIEW
	 * Dashboard, remove all of the chooser code and uncomment the GetString line to get the auto name from the text box
	 * below the Gyro
	 *
	 * You can add additional auto modes by adding additional comparisons to the if-else structure below with additional strings.
	 * If using the SendableChooser make sure to add them to the chooser code above as well.
	 */
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
		SmartDashboard::PutBoolean("Pixy Detected",pixy->Sensor->AddressOnly());

		SmartDashboard::PutNumber("Buffer",pixy->get());

		SmartDashboard::PutBoolean("buffer",);
		//convert(2, 3) + convert(4, 5) + convert(6, 7) + convert(8, 9) + convert(10, 11)
		if(pixy->updateBuffer()){

			SmartDashboard::PutNumber("Check Sum", pixy->get());
			SmartDashboard::PutNumber("Signature", pixy->get());
			SmartDashboard::PutNumber("X Center", pixy->get());
			SmartDashboard::PutNumber("Y Center", pixy->get());
			SmartDashboard::PutNumber("Width", pixy->get());
			SmartDashboard::PutNumber("Height", pixy->get());

		}
		SmartDashboard::PutNumber("Test", 0x55);*/


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


	}

	void TestPeriodic()
	{
		lw->Run();
	}
};

START_ROBOT_CLASS(Robot)
