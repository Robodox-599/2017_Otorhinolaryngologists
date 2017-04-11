#include "MG1.h"

MG1::MG1() {
	// Add Commands here:
	// e.g. AddSequential(new Command1());
	//      AddSequential(new Command2());
	// these will run in order.

	// To run multiple commands at the same time,
	// use AddParallel()
	// e.g. AddParallel(new Command1());
	//      AddSequential(new Command2());
	// Command1 and Command2 will run in parallel.

	// A command group will require all of the subsystems that each member
	// would require.
	// e.g. if Command1 requires chassis, and Command2 requires arm,
	// a CommandGroup containing them would require both the chassis and the
	// arm.

	profile = {{0, 0, 0},
    {0.1, 0.0484, 0.00484},
    {0.2, 0.1936, 0.0242},
    {0.3, 0.484, 0.0726},
    {0.4, 0.8712, 0.15972},
    {0.5, 1.3068, 0.2904},
    {0.6, 1.7424, 0.46464},
    {0.7, 2.178, 0.68244},
    {0.8, 2.6136, 0.9438},
    {0.9, 3.0492, 1.24872},
    {1, 3.4848, 1.5972},
    {1.1, 3.872, 1.9844},
    {1.2, 4.1624, 2.40064},
    {1.3, 4.3076, 2.8314},
    {1.4, 4.356, 3.267},
    {1.5, 4.356, 3.7026},
    {1.6, 4.3076, 4.13336},
    {1.7, 4.1624, 4.5496},
    {1.8, 3.872, 4.9368},
    {1.9, 3.4848, 5.28528},
    {2, 3.0492, 5.5902},
    {2.1, 2.6136, 5.85156},
    {2.2, 2.178, 6.06936},
    {2.3, 1.7424, 6.2436},
    {2.4, 1.3068, 6.37428},
    {2.5, 0.8712, 6.4614},
    {2.6, 0.484, 6.5098},
    {2.7, 0.1936, 6.52916},
    {2.8, 0.0484, 6.534},
    {2.9, 0, 6.534},
    {3, 0, 6.534}
    };
    
    AddSequential(new MotionProfile(profile, profile, 3));
    AddSequential(new WaitTime(1));
    //gear correction
    AddSequential(new Move(-60,-60,.5));
    AddSequential(new WaitTime(.5));
    AddSequential(new Move(60,60,.5));
    AddSequential(new WaitTime(.5));
    AddSequential(new Move(-60,-60,.5));
    AddSequential(new WaitTime(.5));
    AddSequential(new Move(60,60,.5));
    AddSequential(new WaitTime(.5));
}
