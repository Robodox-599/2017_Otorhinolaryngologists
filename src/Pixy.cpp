/*
 * Pixy.cpp
 *
 *  Created on: Jan 8, 2017
 *      Author: Admin
 */
#include "Pixy.h"

Pixy::Pixy()
{
	Sensor = new I2C(I2C::Port::kMXP, 0x54);
	buffer[12] = {};
	sync[1] = {0};
}

Pixy::~Pixy()
{
	delete Sensor;
	Sensor = nullptr;
}

uint8_t Pixy::convert(int index1, int index2)
{
	return buffer[index1] | (buffer[index2] << 8);
}

bool Pixy::updateBuffer()
{
	Sensor->ReadOnly(12, buffer);
	return true;

	/*Sensor->ReadOnly(1, sync);
	if(sync[0] == 0x55)
	{
		Sensor->ReadOnly(1, sync);
		if(sync[0] == 0xaa)
		{
			Sensor->ReadOnly(12, buffer);
			if(convert(0, 1) == convert(2, 3) + convert(4, 5) + convert(6, 7) + convert(8, 9) + convert(10, 11))
			{
				return true;
			}
			//return true;
		}
		//return true;
	}
	return false;*/
}
