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
	uint16_t convert(int one, int two);

private:

	uint8_t sync[2];
	uint8_t buffer[12];


};



#endif /* SRC_PIXY_H_ */
