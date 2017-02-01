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
	bool getIsJoystickForward();

	float abs(float num);

	CANTalon* getCANTalon();

	float forwardSpeed;
	float turnSpeed;

private:
	Talon* frontLeftDrive;
	Talon* backLeftDrive;
	CANTalon* frontRightDrive;
	CANTalon* backRightDrive;



	//true if the driver is turning the robot. Used in straight drive.
	bool isJoystickTurn;

	//true if the driver is driving the robot forward of backwards.
	bool isJoystickForward;

};


#endif /* SRC_DRIVE_H_ */
