/*
 * Gyro.h
 *
 *  Created on: Jan 30, 2017
 *      Author: tons-of-carls
 */

#ifndef SRC_GYRODRIVE_H_
#define SRC_GYRODRIVE_H_


/*MACROS*/
#define GYRO_ERROR_DEADZONE (.5)
#define GYRO_ERROR_LIMIT    (180)

/*INCLUDES*/
#include "AHRS.h"
#include "Drive.h"

  class GyroDrive
  {
  public:
    GyroDrive(Drive* d);
    ~GyroDrive();

    bool straightDrive();
    bool autoTurn(float angle);
    float calculateError();
    void reset();


  private:
    Drive* gDrive;
    AHRS* navX;
    Timer* period;

    float gyroValue;
    float desiredAngle;
    bool hasTimerStarted;
  };


#endif /* SRC_GYRODRIVE_H_ */
