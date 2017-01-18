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
	uint16_t convert();

	uint16_t get();

	uint8_t send[1];

private:

	uint8_t sync[1];
	uint8_t high[1];
	uint8_t low[1];


};



#endif /* SRC_PIXY_H_ */
