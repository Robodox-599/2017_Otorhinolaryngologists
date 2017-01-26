/*
 * Autonomous.h
 *
 *  Created on: Jan 19, 2017
 *      Author: Admin
 */
//Brandon's autonomouses
#ifndef SRC_AUTONOMOUS_H_
#define SRC_AUTONOMOUS_H_
#include "Drive.h"
#include "Gears.h"

class Autonomous
{
public:

	Autonomous(Drive* autoDrive, Gears* autoGear);
	~Autonomous();

	void auto1();
	void auto3();
	void auto5();
	void auto7();
	void overlap1_2();
	void overlap4_6_7();


	int autoSteps;
	bool isTurning;
	bool isDriving;
	bool isGears;



private:

	Drive* drive;
	Gears* gear;

};





#endif /* SRC_AUTONOMOUS_H_ */
