#include <iostream>
#include <memory>
#include <string>

#include <IterativeRobot.h>
#include <LiveWindow/LiveWindow.h>
#include <SmartDashboard/SendableChooser.h>
#include <SmartDashboard/SmartDashboard.h>

#include "CANTalon.h"
#include "Timer.h"

class Robot: public frc::IterativeRobot {
public:
	void RobotInit()
	{
		chooser.AddDefault(autoNameDefault, autoNameDefault);
		chooser.AddObject(autoNameCustom, autoNameCustom);
		frc::SmartDashboard::PutData("Auto Modes", &chooser);
		talon = new CANTalon(1);
		timer = new Timer();
	}

	/*
	 * This autonomous (along with the chooser code above) shows how to select
	 * between different autonomous modes using the dashboard. The sendable
	 * chooser code works with the Java SmartDashboard. If you prefer the
	 * LabVIEW Dashboard, remove all of the chooser code and uncomment the
	 * GetString line to get the auto name from the text box below the Gyro.
	 *
	 * You can add additional auto modes by adding additional comparisons to the
	 * if-else structure below with additional strings. If using the
	 * SendableChooser make sure to add them to the chooser code above as well.
	 */
	void AutonomousInit() override {
		autoSelected = chooser.GetSelected();
		// std::string autoSelected = SmartDashboard::GetString("Auto Selector", autoNameDefault);
		std::cout << "Auto selected: " << autoSelected << std::endl;

		if (autoSelected == autoNameCustom) {
			// Custom Auto goes here
		} else {
			// Default Auto goes here
		}
	}

	void AutonomousPeriodic() {
		if (autoSelected == autoNameCustom) {
			// Custom Auto goes here
		} else {
			// Default Auto goes here
		}
	}

	void TeleopInit()
	{
		talon->Set(.2);
		timer->Reset();
	}

	void TeleopPeriodic()
	{
		float currentAmp = talon->GetOutputCurrent();
		float outputV = talon->GetOutputVoltage();
		int encoderPosition = talon->GetEncPosition();
		int encoderVel = talon->GetEncVel();

		SmartDashboard::PutNumber("Current Amp:", currentAmp);
		SmartDashboard::PutBoolean("Flag:", flag);
		SmartDashboard::PutNumber("Time", timer->Get());

		printf("Current Current:%f\n",currentAmp);
		printf("Current Voltage:%f\n", outputV);

		printf("Encoder Position:%i\n", encoderPosition);
		printf("Encoder Velocity:%i\n\n", encoderVel);

		/*
		if(currentAmp > 2)
		{
			flag = true;
			timer->Start();

			if(timer->HasPeriodPassed(2.0) && flag == true)
			{
				talon->Set(0);
				timer->Stop();
				timer->Reset();
			}
		}
		else
		{
			flag = false;
			timer->Reset();
		}
		*/
	}

	void TestPeriodic() {
		lw->Run();
	}

private:
	frc::LiveWindow* lw = LiveWindow::GetInstance();
	frc::SendableChooser<std::string> chooser;
	const std::string autoNameDefault = "Default";
	const std::string autoNameCustom = "My Auto";
	std::string autoSelected;

	CANTalon* talon;
	Timer* timer;

	bool flag = false;

};

START_ROBOT_CLASS(Robot)
