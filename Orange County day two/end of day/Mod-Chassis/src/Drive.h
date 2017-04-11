/*
 * Drive.h
 *
 *  Created on: Jan 30, 2017
 *      Author: tons-of-carls
 */

#ifndef SRC_DRIVE_H_
#define SRC_DRIVE_H_

#include "WPILib.h"
#include "CANTalon.h"

using namespace std;

class Drive
{
public:
	Drive();
	~Drive();

	void resetAutoDriving();

	void drive(float xAxis, float yAxis);

	void setForwardSpeed(float rawY);
	void addForwardSpeed(float increment);

	void setTurnSpeed(float rawX);
	void addTurnSpeed(float increment);

	void updateLeftMotors(float speed);
	void updateRightMotors(float speed);
	void updateAllMotors();

	bool getIsJoystickTurn();

	void setLowGear();

	bool getIsJoystickForward();

	float abs(float num);
	int sign(float value);

	void shift(bool toggleShift);
	void setRampRates(int voltage);

	void addOffsetLeftTurn(float offset);
	void addOffsetRightTurn(float offset);

	string getShiftState();

	CANTalon* getCANTalon();
	CANTalon* getCANTalonLeft();



private:
	CANTalon* frontLeftDrive;
	CANTalon* backLeftDrive;
	CANTalon* frontRightDrive;
	CANTalon* backRightDrive;

	DoubleSolenoid* shifter;

	bool shifterButtonPress;

	//true if the driver is turning the robot. Used in straight drive.
	bool isJoystickTurn;

	//true if the driver is driving the robot forward of backwards.
	bool isJoystickForward;

	float forwardSpeed;
	float turnSpeed;

	float rightOffset;
	float leftOffset;

};


#endif /* SRC_DRIVE_H_ */
