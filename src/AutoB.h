/*
 * Auto.h
 *
 *  Created on: Jan 19, 2017
 *      Author: Admin
 */
//Brandon's autonomouses
#ifndef SRC_AUTOB_H_
#define SRC_AUTOB_H_

class Auto
{
public:

	Auto(Drive* autoDrive, Gears* autoGear);
	~Auto();

	void auto1();
	void auto3();
	void auto5();
	void auto7();


	int autoSteps;
	bool isTurning;
	bool isDriving;
	bool isGears;



private:

	Drive*drive;
	Gears*gear;

};





#endif /* SRC_AUTOB_H_ */
