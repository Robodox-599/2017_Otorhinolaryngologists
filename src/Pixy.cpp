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
	high[1] = {};
	low[1] = {};
	sync[1] = {0};
}

Pixy::~Pixy()
{
	delete Sensor;
	Sensor = nullptr;
}

uint16_t Pixy::convert()
{
	return high[0] | (low[0] << 8);
}

uint16_t Pixy::get()
{
	Sensor->ReadOnly(1, low);
	//Sensor->ReadOnly(1, high);
	return low[0];//convert();
}

bool Pixy::updateBuffer()
{
	/*
	Sensor->ReadOnly(12, buffer);
	return true;
	Sensor->ReadOnly(12, buffer);
			if(convert(0, 1) == convert(2, 3) + convert(4, 5) + convert(6, 7) + convert(8, 9) + convert(10, 11))
			{
				return true;
			}
			//return true;
	*/
	high[0] = 0;
	low[0] = 0;
	sync[0] = 0;

	Sensor->ReadOnly(1, sync);
	if(sync[0] == 0x55)
	{
		Sensor->ReadOnly(1, sync);
		if(sync[0] == 0xaa)
		{
			return true;
		}
		//return true;
	}
	return false;
}
