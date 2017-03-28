/*
 * Gyro.h
 *
 *  Created on: Jan 30, 2017
 *      Author: tons-of-carls
 */

#ifndef SRC_GYRODRIVE_H_
#define SRC_GYRODRIVE_H_


/*MACROS*/
#define GYRO_ERROR_DEADZONE (.5)//test deadzone, gyro not resetting after auto turning
#define GYRO_ERROR_LIMIT    (180.0)

/*INCLUDES*/
#include "AHRS.h"
#include "Drive.h"
#include "WPILib.h"

class GyroDrive
{
public:
	GyroDrive(Drive* d);
	~GyroDrive();

	bool straightDrive();
	bool autoTurn(float angle);
	float calculateError();
	void reset();
	bool isGyroStable();

private:
	Drive* gDrive;
	AHRS* navX;

	float gyroValue;
	float desiredAngle;
	float integrator;

	float maxTurnSpeed;
};


#endif /* SRC_GYRODRIVE_H_ */
