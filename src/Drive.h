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

	bool autoEncDistance (float desiredDistance);

	void drive(float xAxis, float yAxis);

	void setForwardSpeed(float rawY);
	void setTurnSpeed(float rawX);

	void updateLeftMotors(float speed);
	void updateRightMotors(float speed);
	
	bool setAutoTurning(float angle);
	void resetGyro(float offSet = 0);

	bool globalAutoTurning(float angle);

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

	/*int encError;
	int desiredTicks;
	int encStartPosition;
	int encTargetPosition;*/

	bool isDriving;
	int autoDrivingError;
	float distance;
	
	//Auto Turning Variables
	bool isAutoTurning;


	//Mic
	float globalGyro;
};



#endif /* SRC_DRIVE_DRIVE_H_ */
