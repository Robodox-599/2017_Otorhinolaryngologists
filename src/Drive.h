/*
 * Drive.h
 *
 *  Created on: Mar 27, 2016
 *      Author: Robodox 599
 */

#ifndef SRC_DRIVE_DRIVE_H_
#define SRC_DRIVE_DRIVE_H_

#include "WPILib.h"
#include "AHRS.h"
#include "CANTalon.h"

class Drive
{
public:
	Drive();
	~Drive();

	void drive(float xAxis, float yAxis);

	void setForwardSpeed(float rawY);
	void setTurnSpeed(float rawX);

	void updateLeftMotors(float speed);
	void updateRightMotors(float speed);
	
	void setAutoTurning(float angle);
	void endAutoTurning();
	void resetGyro(float offSet = 0);

	void globalAutoTurning(float angle);

	AHRS* navX;
	

	
	float error;

private:

	float abs(float num);

	CANTalon* frontLeftDrive;
	CANTalon* backLeftDrive;
	CANTalon* frontRightDrive;
	CANTalon* backRightDrive;

	float forwardSpeed;
	float turnSpeed;

	//Straight Drive Variables
	float gyroValue;
	float refAngle;

	float const kp = 0.01;
	
	//Auto Turning Variables
	bool isAutoTurning;
	bool needsReset;


	//Mic
	float globalGyro;
};



#endif /* SRC_DRIVE_DRIVE_H_ */
