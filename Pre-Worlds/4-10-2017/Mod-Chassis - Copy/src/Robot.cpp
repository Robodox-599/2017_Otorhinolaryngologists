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

		auton = new Autonomous(gears, nvxDrive, encDrive, pxyDrive, drive);
		autoini = false;

		hasFinished = false;
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
		nvxDrive->reset();
		encDrive->reset();
		lift->reset();
		auton->autoReset();
		hasFinished = false;
		drive->setLowGear();

		Wait(.25);
	}

	void AutonomousPeriodic()
	{
		/*if(!autoini)
		{
			nvxDrive->reset();
			encDrive->reset();
			lift->reset();
			auton->autoReset();
			autoini = true;
		}
		if (!hasFinished)
		{
			auton->linearBasicAuto1(60);

			hasFinished = true;
		}*/

		SmartDashboard::PutNumber("encoder value 1", drive->getCANTalon()->GetEncPosition());
		SmartDashboard::PutNumber("encoder value 2", drive->getCANTalonLeft()->GetEncPosition());

		//pxyDrive->update();
		drive->drive(0,0);

		//auton->middleGear();
		auton->gearSide(50);//was 60 -> 58 ->54
		//auton->gearSide(-58);

		drive->updateAllMotors();
	}

	void TeleopInit()
	{
		nvxDrive->reset();
		encDrive->reset();
		lift->reset();
	}

	void TeleopPeriodic()
	{

		SmartDashboard::PutBoolean("Pixy update", pxyDrive->update());
		SmartDashboard::PutNumber("pixy value", pxyDrive->turnError());

		SmartDashboard::PutNumber("enc val left", drive->getCANTalonLeft()->GetEncPosition());
		SmartDashboard::PutNumber("enc val right", drive->getCANTalon()->GetEncPosition());

		if(xbox->GetBumper(XboxController::JoystickHand::kLeftHand) || xbox->GetBumper(XboxController::JoystickHand::kRightHand))
		{
			drive->drive(xbox->GetX(XboxController::kRightHand), xbox->GetY(XboxController::kLeftHand));
		}
		else
		{
			drive->drive(xbox->GetX(XboxController::kRightHand), -xbox->GetY(XboxController::kLeftHand));
		}

		//pxyDrive->update();

		/*if(xbox->GetAButton())
		{
			//pxyDrive->trackTurn();
			nvxDrive->teleopSet();
			drive->getCANTalon()->SetEncPosition(0);
		}
		else if(xbox->GetYButton())
		{
			encDrive->setDistance(30);
		}
		else
		{
			encDrive->precisionDistance();
		}*/

		if(!lift->getLiftToggle())
		{
			nvxDrive->straightDrive();
		}

		if(atk3->GetRawButton(6))
		{
			lift->resetLiftToggle();
		}

		drive->shift(xbox->GetBButton());

		drive->updateAllMotors();




		lift->liftRobot(atk3->GetRawButton(1));
		gears->intakeRotator(atk3->GetRawButton(3));

		gears->trapDoorOpen(atk3->GetRawButton(11));
		gears->trapDoorClose(atk3->GetRawButton(10));
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

	bool autoini;

	bool hasFinished;
};

START_ROBOT_CLASS(Robot)
