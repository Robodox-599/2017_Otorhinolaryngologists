/*
 * GyroDrive.cpp
 *
 *  Created on: Jan 30, 2017
 *      Author: tons-of-carls
 */

#include "GyroDrive.h"

GyroDrive::GyroDrive(Drive* d)
{
  gDrive = d;
  navX = new AHRS(SPI::Port::kMXP);
  period = new Timer();

  navX->ZeroYaw();

  gyroValue = 0;
  desiredAngle = 0;
  hasTimerStarted = false;
}

GyroDrive::~GyroDrive()
{
  gDrive = nullptr;
  navX = nullptr;
  period = nullptr;

  delete gDrive;
  delete navX;
  delete period;
}

bool GyroDrive::straightDrive()
{
  gyroValue = navX->GetYaw();

  if(gDrive->getIsJoystickTurn())
  {
    period->Start();
    hasTimerStarted = true;
  }
  else if(!period->HasPeriodPassed(2) && hasTimerStarted)
  {
    //Time is passing, are you?
    reset();
  }
  else if((calculateError() > GYRO_ERROR_DEADZONE && calculateError() < GYRO_ERROR_LIMIT) || (calculateError() < -GYRO_ERROR_DEADZONE && calculateError() > -GYRO_ERROR_LIMIT))
  {
    gDrive->addTurnSpeed(calculateError() / (GYRO_ERROR_LIMIT - GYRO_ERROR_DEADZONE));
    return false;
  }
  else
  {
	  period->Stop();
	  period->Reset();
	  hasTimerStarted = false;
  }
  return true;
}

bool GyroDrive::autoTurn(float angle)
{
  desiredAngle = angle;
  return straightDrive();
}

float GyroDrive::calculateError()
{
  return desiredAngle - gyroValue;
}

void GyroDrive::reset()
{
  navX->ZeroYaw();

  gyroValue = 0;
  desiredAngle = 0;
}


