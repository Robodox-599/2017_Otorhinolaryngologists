/*
 * PixyLego.cpp
 *
 *  Created on: Jan 9, 2017
 *      Author: tons-of-carls
 */
#include "PixyLego.h"

PixyLego::PixyLego()
{
	I2C = new I2C(I2C::Port::kMXP, 1);
	general[6] = {0,0,0,0,0,0};
}

PixyLego::~PixyLego()
{
	I2C = nullptr;
	delete I2C;
}

void PixyLego::getGeneral()
{
	I2C->Read(0x50, 6, general);
}

uint16_t PixyLego::combine()
{
	return (general[1] << 8) | general[0];
}

