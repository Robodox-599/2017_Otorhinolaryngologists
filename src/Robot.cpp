#include <iostream>
#include <memory>
#include <string>


#include "Drive.h"
#include "AutoDrive.h"
#include "GyroDrive.h"
#include "VisionTracking.h"
#include "Autonomous.h"

#include "Gears.h"
#include "Lift.h"

#include <IterativeRobot.h>
#include <LiveWindow/LiveWindow.h>
#include <SmartDashboard/SendableChooser.h>
#include <SmartDashboard/SmartDashboard.h>

class Robot: public frc::IterativeRobot {
public:
	void RobotInit()
	{
		chooser.AddDefault(autoNameDefault, autoNameDefault);
		chooser.AddObject(autoNameCustom, autoNameCustom);
		frc::SmartDashboard::PutData("Auto Modes", &chooser);

		drive = new Drive();

		encDrive = new AutoDrive(drive);
		pxyDrive = new VisionTracking(drive);
		nvxDrive = new GyroDrive(drive);

		comp599 = new Compressor();
		comp599->SetClosedLoopControl(true);

		lift = new Lift();
		gears = new Gears();

		xbox = new XboxController(0);
		atk3 = new Joystick(1);

		auton = new Autonomous();

		CameraServer::GetInstance()->StartAutomaticCapture();
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
	void AutonomousInit() override
	{
		autoSelected = chooser.GetSelected();
		// std::string autoSelected = SmartDashboard::GetString("Auto Selector", autoNameDefault);
		std::cout << "Auto selected: " << autoSelected << std::endl;

		if (autoSelected == autoNameCustom)
		{
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
		auton->auto3();
		drive->updateAllMotors();
	}

	void TeleopInit()
	{
		nvxDrive->reset();
		drive->getCANTalon()->SetEncPosition(0);
		lift->reset();
	}

	void TeleopPeriodic()
	{
		if(xbox->GetBumper(XboxController::JoystickHand::kLeftHand) || xbox->GetBumper(XboxController::JoystickHand::kRightHand))
		{
			drive->drive(-xbox->GetX(XboxController::kRightHand), xbox->GetY(XboxController::kLeftHand));
		}
		else
		{
			drive->drive(-xbox->GetX(XboxController::kRightHand), -xbox->GetY(XboxController::kLeftHand));
		}

		//pxyDrive->update();

		/*if(xbox->GetAButton())
		{
			pxyDrive->trackTurn();
			nvxDrive->reset();
			drive->getCANTalon()->SetEncPosition(0);
		}*/
		if(!lift->getLiftToggle())
		{
			nvxDrive->straightDrive();
		}

		if(atk3->GetRawButton(10))
		{
			lift->resetLiftToggle();
		}

		drive->shift(xbox->GetBButton());

		SmartDashboard::PutNumber("Turn Speed", drive->turnSpeed);
		SmartDashboard::PutNumber("Forward Speed", drive->forwardSpeed);

		SmartDashboard::PutNumber("Gyro Error", nvxDrive->calculateError());

		drive->updateAllMotors();


		lift->liftRobot(atk3->GetRawButton(6));
		gears->intakeRotator(atk3->GetRawButton(8));
		gears->trapDoor();

		gears->toggleTrapDoor(atk3->GetRawButton(9));

		SmartDashboard::PutBoolean("Break Beam One", lift->beamOne());
		SmartDashboard::PutBoolean("Break Beam Two", lift->beamTwo());

		SmartDashboard::PutBoolean("Initial Break", lift->initialBreak());

		SmartDashboard::PutString("Trap Door State", gears->trapDoorState());
		SmartDashboard::PutString("Gear Intake State", gears->rotatorState());

		SmartDashboard::PutBoolean("Plate One", gears->getPlateOne());
		SmartDashboard::PutBoolean("Plate Two", gears->getPlateTwo());

		SmartDashboard::PutString("Shift State", drive->getShiftState());

		SmartDashboard::PutBoolean("Gear Pressure Plate Status", gears->getPressurePlateStatus());

		SmartDashboard::PutNumber("Lift Status", lift->getLiftStatus());

		SmartDashboard::PutNumber("Lift ENC", lift->leftCimMotor->GetEncPosition());
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
	Compressor* comp599;

	Lift* lift;
	Gears* gears;

	XboxController* xbox;
	Joystick* atk3;
	Autonomous* auton;
};

START_ROBOT_CLASS(Robot)













/*
else if(xbox->GetRawButton(8))
{
	encDrive->setDistance(100);
	//nvxDrive->straightDrive();
}
else if(xbox->GetRawButton(11))
{
	nvxDrive->autoTurn(90);
	drive->getCANTalon()->SetEncPosition(0);
}
else
{
	nvxDrive->straightDrive();
	//encDrive->precisionDistance();
}*/













//OLD ROBOT FILE
/*#include <Autonomous.h>
#include <iostream>
#include <memory>
#include <string>

#include "WPILib.h"
#include "XboxController.h"
#include "Drive.h"
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
	 *
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
	Autonomous* autoB;
	XboxController* xbox;
};

START_ROBOT_CLASS(Robot)*/
