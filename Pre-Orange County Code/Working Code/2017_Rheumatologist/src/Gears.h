/*
 * Gears.h
 *
 *  Created on: Jan 11, 2017
 *      Author: Admin
 */

#ifndef SRC_GEARS_H_
#define SRC_GEARS_H_
#include "WPILib.h"


using namespace std;

class Gears
{
	public:
		Gears();
		~Gears();

		void intakeRotator(bool rotate);

		void trapDoorClose(bool close);//changed because of driver preference
		void trapDoorOpen(bool open);
		bool trapDoor();
		bool getPlateOne();
		bool getPlateTwo();

		string trapDoorState();
		string rotatorState();
		bool getPressurePlateStatus();

		bool rState;
		bool tdState;






	private:

		DoubleSolenoid* intakeRotatorSol;

		DoubleSolenoid* trapDoorSol;

		DigitalInput* plateOne;
		//DigitalInput* plateTwo;

		Timer* timeSpent;




};




#endif /* SRC_GEARS_H_ */
