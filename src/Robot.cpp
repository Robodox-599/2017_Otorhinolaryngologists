#include <Autonomous.h>
#include <iostream>
#include <memory>
#include <string>

#include "WPILib.h"
#include "XboxController.h"
#include "Drive.h"
#include "Auto.h"
#include "Autonomous.h"
#include "Gears.h"
#include "Lift.h"

#include <IterativeRobot.h>
#include <LiveWindow/LiveWindow.h>
#include <SmartDashboard/SendableChooser.h>
#include <SmartDashboard/SmartDashboard.h>

class Robot: public IterativeRobot {
public:
	void RobotInit() {
		chooser.AddDefault(autoNameDefault, autoNameDefault);
		chooser.AddObject(autoNameCustom, autoNameCustom);
		frc::SmartDashboard::PutData("Auto Modes", &chooser);
		drive = new Drive();
		gears = new Gears();
		lift = new Lift();
		autoA = new Auto(drive, gears);
		autoB = new Autonomous(drive, gears);
		xbox = new XboxController(0); //usb port


		SmartDashboard::PutBoolean("Gear Piston Position: ", gears->retracted);
		SmartDashboard::PutBoolean("Pressure Plate Status: ", gears->pressurePlate);
		SmartDashboard::PutNumber("Current Amps (small spike = caught, big spike = top): ", drive->frontLeftDrive->GetOutputCurrent()); //motor w enc
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

	void TeleopInit() {

	}

	void TeleopPeriodic() {
		drive->drive(xbox->GetX(XboxController::kRightHand), xbox->GetY(XboxController::kLeftHand));
		lift->liftCimMotors(xbox->GetAButton());
		gears->intakeRotator(xbox->GetBButton());

	}

	void TestPeriodic() {
		lw->Run();
	}

private:
	LiveWindow* lw = LiveWindow::GetInstance();
	SendableChooser<std::string> chooser;
	const std::string autoNameDefault = "Default";
	const std::string autoNameCustom = "My Auto";
	std::string autoSelected;

	Drive* drive;
	Gears* gears;
	Lift* lift;
	Auto* autoA;
	Autonomous* autoB;
	XboxController* xbox;
};

START_ROBOT_CLASS(Robot)
