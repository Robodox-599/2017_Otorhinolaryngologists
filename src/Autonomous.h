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

class Autonomous
{
public:

	Autonomous(Gears* autoGear, GyroDrive* autoTurning, AutoDrive* precisionDrive, VisionTracking* vt);
	~Autonomous();

	void auto1();
	void auto2();
	void auto3();
	void auto4();
	void auto5();
	void auto6();
	void auto7();
	void overlap1_2();
	void overlap4_6_7();
	void gearsReset();


	int autoSteps;
	bool isTurning;
	bool isDriving;
	bool isGears;



private:

	GyroDrive* gyroDrive;
	AutoDrive* encDrive;
	VisionTracking* pxyDrive;

	Gears* gear;

};





#endif  SRC_AUTONOMOUS_H_
