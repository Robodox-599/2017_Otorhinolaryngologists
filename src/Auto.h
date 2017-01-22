/*
 * Auto.h
 *
 *  Created on: Jan 19, 2017
 *      Author: Admin
 */

#ifndef SRC_AUTO_H_
#define SRC_AUTO_H_
#include "Drive.h"
#include "Gears.h"

class Auto
{
public:

	Auto(Drive* autoDrive, Gears* autoGear);
	~Auto();

	void auto2();
	void auto4();
	void auto6();

	int autoSteps;
	bool isTurning;
	bool isDriving;
	bool isGears;

private:

	Drive*drive;
	Gears*gear;

};





#endif /* SRC_AUTO_H_ */
