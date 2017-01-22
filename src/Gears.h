/*
 * Gears.h
 *
 *  Created on: Jan 11, 2017
 *      Author: Admin
 */

#ifndef SRC_GEARS_H_
#define SRC_GEARS_H_
#include "WPILib.h"

class Gears
{
	public:
		Gears();
		~Gears();

		void intakeRotator(bool rotate);


		bool trapDoor();

		bool retracted;






	private:

		DoubleSolenoid*intakeRotatorSol;

		DoubleSolenoid*trapDoorSol;

		DigitalInput*pressurePlate;

		Timer*timeSpent;




};




#endif /* SRC_GEARS_H_ */
