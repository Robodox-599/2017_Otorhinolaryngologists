/*
 * Auto.cpp
 *
 *  Created on: Jan 19, 2017
 *      Author: Admin
 */
#include "Auto.h"






void Auto::auto1()
{
	if(auto1Steps == 0)
	{
		//Move Forward

		if(isDriving && isGears)
		{
			auto1Steps = 1;
			isDriving = false;
			isGears = false;
		}
	}

	if(auto1Steps == 1)
	{
		//Put Gear

		if(isGears)
		{
			auto1Steps = 2;
			isGears = false;
		}
	}

	if(auto1Steps == 2)
	{
		//Turn

		if(isDriving)
		{
			auto1Steps = 3;
			isDriving = false;
		}
	}

	if(auto1Steps == 3)
	{
		//Drive forward (hit ball deposit)

		if(isDriving)
		{
			auto1Steps = 4;
			isDriving = false;
		}
	}

	if(auto1Steps == 4)
	{
		//Turn

		if(isDriving)
		{
			auto1Steps = 5;
			isDriving = false;
		}
	}

	if(auto1Steps == 5)
	{
		//Drive forward

		if(isDriving)
		{
			isDriving = false;
		}
	}
}

