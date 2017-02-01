#include <iostream>
#include <memory>
#include <string>


#include "Drive.h"

#include "AutoDrive.h"
#include "GyroDrive.h"
#include "VisionTracking.h"

#include <IterativeRobot.h>
#include <LiveWindow/LiveWindow.h>
#include <SmartDashboard/SendableChooser.h>
#include <SmartDashboard/SmartDashboard.h>

class Robot: public frc::IterativeRobot {
public:
	void RobotInit() {
		chooser.AddDefault(autoNameDefault, autoNameDefault);
		chooser.AddObject(autoNameCustom, autoNameCustom);
		frc::SmartDashboard::PutData("Auto Modes", &chooser);

		drive = new Drive();

		encDrive = new AutoDrive(drive);
		pxyDrive = new VisionTracking(drive);
		nvxDrive = new GyroDrive(drive);

		xbox = new XboxController(0);
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

	void AutonomousPeriodic()
	{
		if (autoSelected == autoNameCustom)
		{
			// Custom Auto goes here
		}
		else
		{
			// Default Auto goes here
		}
	}

	void TeleopInit()
	{

	}

	void TeleopPeriodic()
	{
		if(xbox->GetYButton())
		{
			drive->drive(-xbox->GetX(XboxController::kRightHand), -xbox->GetY(XboxController::kLeftHand));
		}
		else
		{
			drive->drive(xbox->GetX(XboxController::kRightHand), xbox->GetY(XboxController::kLeftHand));
		}

		if(xbox->GetAButton())
		{
			pxyDrive->trackForward(30);
			pxyDrive->trackTurn();
			nvxDrive->reset();
		}
		else if(xbox->GetBButton())
		{
			encDrive->precisionDistance(10);
			nvxDrive->straightDrive();
		}
		else if(xbox->GetXButton())
		{
			nvxDrive->autoTurn(30);
		}
		else
		{
			nvxDrive->straightDrive();
		}

		SmartDashboard::PutNumber("Turn Speed", drive->turnSpeed);
		SmartDashboard::PutNumber("Forward Speed", drive->forwardSpeed);

		drive->updateAllMotors();
	}

	void TestPeriodic()
	{
		lw->Run();
	}

private:
	frc::LiveWindow* lw = LiveWindow::GetInstance();
	frc::SendableChooser<std::string> chooser;
	const std::string autoNameDefault = "Default";
	const std::string autoNameCustom = "My Auto";
	std::string autoSelected;

	Drive* drive;

	AutoDrive* encDrive;
	VisionTracking* pxyDrive;
	GyroDrive* nvxDrive;

	XboxController* xbox;
};

START_ROBOT_CLASS(Robot)
