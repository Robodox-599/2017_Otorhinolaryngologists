/*
 * Pixy.h
 *
 *  Created on: Jan 8, 2017
 *      Author: Admin
 */
#include "WPILib.h"
#ifndef SRC_PIXY_H_
#define SRC_PIXY_H_

class Pixy
{
public:
	Pixy();
	~Pixy();

	I2C* Sensor;

	bool updateBuffer();
	uint8_t convert(int index1, int index2);
	uint8_t buffer[12];

private:

	uint8_t sync[1];

};



#endif /* SRC_PIXY_H_ */
