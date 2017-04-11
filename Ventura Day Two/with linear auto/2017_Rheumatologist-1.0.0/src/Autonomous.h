/*
 * Autonomous.h
 *
 *  Created on: Jan 19, 2017
 *      Author: Admin
 */
//Brandon's autonomouses
#ifndef SRC_AUTONOMOUS_H_
#define SRC_AUTONOMOUS_H_

#include "AutoDrive.h"
#include "GyroDrive.h"
#include "Gears.h"
#include "VisionTracking.h"
#include "Drive.h"

class Autonomous
{
public:

	Autonomous(Gears* autoGear, GyroDrive* autoTurning, AutoDrive* precisionDrive, VisionTracking* vt, Drive* dr);
	~Autonomous();

	void auto1();
	void auto2();
	void auto3();
	void auto4();
	void auto5();
	void auto6();
	void auto7();



	void resetTimer();

	void overlap1_2();
	void overlap4_6_7();
	void gearsReset();

	void basicAuto1();

	void autoReset();


	//All versions of auto 3

	void linearAuto3();

	void linearBasicAuto1(float angle);


private:

	GyroDrive* gyroDrive;
	AutoDrive* encDrive;
	VisionTracking* pxyDrive;
	Drive* drive;
	Timer* time;
	Gears* gear;

	double autoSteps;
	bool isTurning;
	bool isDriving;
	bool isGears;

};

#endif  /*SRC_AUTONOMOUS_H_*/
