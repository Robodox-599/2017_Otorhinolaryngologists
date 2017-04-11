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
	buffer[28] = {};
	sync[2] = {};
	pixyValues[6] = {};
	blockRecieved = 0;
}

Pixy::~Pixy()
{
	delete Sensor;
	Sensor = nullptr;
}


//Byte one: 0101 0101
//Byte two: 1010 1010

// << : 1010 1010 0000 0000
// | : 1010 1010 0000 0000 + 0101 0101 = 1010 1010 0101 0101
void Pixy::convert(int byteOne, int byteTwo, uint16_t block[])
{
	block[byteOne/2] = buffer[byteOne] | (buffer[byteTwo] << 8);
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

					Sensor->Transaction(NULL, 0, buffer, 28);
					convert(0,1,pixyValues);
					convert(2,3,pixyValues);
					convert(4,5,pixyValues);
					convert(6,7,pixyValues);
					convert(8,9,pixyValues);
					convert(10,11,pixyValues);

					if(pixyValues[0] == pixyValues[1] + pixyValues[2] + pixyValues[3] + pixyValues[4] + pixyValues[5])
					{
						blockRecieved++;
						return true;
					}
				}
			}
		}
	}
	blockRecieved = 0;
	return false;
}

uint16_t Pixy::getValue(Value v)
{
	return pixyValues[v];
}

bool Pixy::getBlockStatus()
{
	if(blockRecieved == 0)
	{

		return false;
	}
	return true;
}
