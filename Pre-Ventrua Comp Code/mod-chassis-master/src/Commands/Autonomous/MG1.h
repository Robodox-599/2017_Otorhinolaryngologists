#ifndef MG1_H
#define MG1_H

#include <Commands/CommandGroup.h>

class MG1 : public CommandGroup {
public:
	MG1();
	
	float profile[][3];
};

#endif  // MG1_H
