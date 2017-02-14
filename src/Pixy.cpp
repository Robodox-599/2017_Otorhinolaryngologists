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
	pixyLeftValues[6] = {};
	pixyRightValues[6] = {};
	blockRecieved = 0;
}

Pixy::~Pixy()
{
	delete Sensor;
	Sensor = nullptr;
}

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
					convert(0,1,pixyLeftValues);
					convert(2,3,pixyLeftValues);
					convert(4,5,pixyLeftValues);
					convert(6,7,pixyLeftValues);
					convert(8,9,pixyLeftValues);
					convert(10,11,pixyLeftValues);

					convert(16,17,pixyRightValues);
					convert(18,19,pixyRightValues);
					convert(20,21,pixyRightValues);
					convert(22,23,pixyRightValues);
					convert(24,25,pixyRightValues);
					convert(26,27,pixyRightValues);
					if(pixyLeftValues[0] == pixyLeftValues[1] + pixyLeftValues[2] + pixyLeftValues[3] + pixyLeftValues[4] + pixyLeftValues[5])
					{
						if(pixyRightValues[0] == pixyRightValues[1] + pixyRightValues[2] + pixyRightValues[3] + pixyRightValues[4] + pixyRightValues[5])
						{
							blockRecieved = 0;
							return true;
						}
						blockRecieved = 0;
						return true;
					}
				}
			}
		}
	}



	blockRecieved++;
	return false;
}

uint16_t Pixy::getValue(Value v)
{
	return (pixyLeftValues[v] + pixyRightValues[v])/2;
}

int Pixy::getBlockStatus()
{
	if(blockRecieved > 1)
	{

		return false;
	}
	return true;
}
