/*
 * Pixy.cpp
 *
 *  Created on: Jan 8, 2017
 *      Author: Admin
 */
#include "Pixy.h"

Pixy::Pixy()
{
	Sensor = new I2C(I2C::Port::kOnboard, 0x2);
	buffer[12] = {};
	sync[2] = {};
}

Pixy::~Pixy()
{
	delete Sensor;
	Sensor = nullptr;
}

uint16_t Pixy::convert(int one, int two)
{
	return buffer[one] | (buffer[two] << 8);
}

bool Pixy::updateBuffer()
{
	Sensor->Transaction(NULL, 0, sync, 1);
	if(sync[0] == 85)
	{
		Sensor->Transaction(NULL, 0, sync, 1);
		if(sync[0] == 170)
		{
			Sensor->Transaction(NULL, 0, sync, 1);
			if(sync[0] == 85)
			{
				Sensor->Transaction(NULL, 0, sync, 1);
				if(sync[0] == 170)
				{
					Sensor->Transaction(NULL, 0, buffer, 12);
					return true;
				}
			}
		}
	}
	else if(sync[0] == 0)
	{
		//no object detected
		//place appropriate code
	}
	return false;
}
