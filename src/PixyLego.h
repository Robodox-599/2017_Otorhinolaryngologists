/*
 * PixyLego.h
 *
 *  Created on: Jan 9, 2017
 *      Author: tons-of-carls
 */
#include "WPILib.h"
#ifndef SRC_PIXYLEGO_H_
#define SRC_PIXYLEGO_H_


class PixyLego
{
public:
	PixyLego();
	~PixyLego();

	void getGeneral();
	uint16_t combine();

private:
	I2C* I2C;
	unsigned char general[6];
};


#endif /* SRC_PIXYLEGO_H_ */
