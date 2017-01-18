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

		void trapDoor();





	private:

		DoubleSolenoid*intakeRotatorSol;

		DoubleSolenoid*trapDoorSol;

		DigitalInput*pressurePlate;




};




#endif /* SRC_GEARS_H_ */
