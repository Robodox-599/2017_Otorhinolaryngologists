/*
 * Pixy.cpp
 *
 *  Created on: Jan 8, 2017
 *      Author: Admin
 */
#include "Pixy.h"

Pixy::Pixy()
{
	Sensor = new I2C(I2C::Port::kOnboard, 0x54);
	buffer[4] = {0,0,0,0};
}

Pixy::~Pixy()
{
	delete Sensor;
	Sensor = nullptr;
}

uint8_t Pixy::get()
{
	Sensor->ReadOnly(1, buffer);
	return buffer[0];
}
