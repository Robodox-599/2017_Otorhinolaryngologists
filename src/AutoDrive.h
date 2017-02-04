/*
 * autoDrive.h
 *
 *  Created on: Jan 30, 2017
 *      Author: tons-of-carls
 */

#ifndef SRC_AUTODRIVE_H_
#define SRC_AUTODRIVE_H_

#include "Drive.h"

class AutoDrive
{
public:
	AutoDrive(Drive* d);
	~AutoDrive();

	bool precisionDistance();
	float distanceError();
	void setDistance(float distance);

private:
	Drive* adDrive;

	bool isAutoDrive;
	float dis;

};



#endif /* SRC_AUTODRIVE_H_ */
