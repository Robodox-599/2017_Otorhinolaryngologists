/*
 * VisionTracking.cpp
 *
 *  Created on: Jan 30, 2017
 *      Author: tons-of-carls
 */

#include "VisionTracking.h"

VisionTracking::VisionTracking(Drive* d)
{
  vtDrive = d;
  pixy = new Pixy();

  getFrame = false;
}

VisionTracking::~VisionTracking()
{
  vtDrive = nullptr;
  pixy = nullptr;

  delete vtDrive;
  delete pixy;
}

bool VisionTracking::trackForward(int width)
{
	getFrame = pixy->updateBuffer();
	if(getFrame && (forwardError(width) > 1.5 || forwardError(width) < -1.5))
	{
	vtDrive->addForwardSpeed(forwardError(width) / 100.0);
	return false;
	}
	return true;
}

void VisionTracking::resetForward()
{
  //may need in future if vision tracking starts acting up
}

int VisionTracking::forwardError(int width)
{
  return pixy->getValue(Pixy::Value::WIDTH) - width;
}


bool VisionTracking::trackTurn()
{
  if(getFrame && (turnError() > 1.5 || turnError() < 1.5))
  {
	  vtDrive->addTurnSpeed(turnError() / 100.0);//lower to turn faster, increase to turn slower
	  return false;
  }
  return true;
}

void VisionTracking::resetTurn()
{
  //may need in future if vision tracking starts to act up
}

int VisionTracking::turnError()
{
  return pixy->getValue(Pixy::Value::X_CENTER) - 150;//may need to switch if turning wrong way
}
