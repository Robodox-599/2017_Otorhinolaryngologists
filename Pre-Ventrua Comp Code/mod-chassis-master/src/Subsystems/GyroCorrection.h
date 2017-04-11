#ifndef GyroCorrection_H
#define GyroCorrection_H

#include <Commands/Subsystem.h>

#include "AHRS.h"

class GyroCorrection : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	AHRS* navX;

public:
	GyroCorrection();
	void InitDefaultCommand();
};

#endif  // GyroCorrection_H
