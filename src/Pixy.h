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

	uint8_t get();

private:
	uint8_t buffer[1];

};



#endif /* SRC_PIXY_H_ */
