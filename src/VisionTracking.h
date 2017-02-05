/*
 * VisionTracking.h
 *
 *  Created on: Jan 30, 2017
 *      Author: tons-of-carls
 */

#ifndef SRC_VISIONTRACKING_H_
#define SRC_VISIONTRACKING_H_

#include "Pixy.h"
#include "Drive.h"

class VisionTracking
{
public:
	VisionTracking(Drive* d);
	~VisionTracking();

	//Forward
	bool trackForward(int width);
	void resetForward();
	int forwardError(int width);

	//Turn
	bool trackTurn();
	void resetTurn();
	int turnError();

	//General
	void update();

private:
	Drive* vtDrive;
	Pixy* pixy;

	bool getFrame;
};




#endif /* SRC_VISIONTRACKING_H_ */
