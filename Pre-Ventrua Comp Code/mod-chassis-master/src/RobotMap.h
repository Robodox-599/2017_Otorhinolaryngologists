#ifndef ROBOTMAP_H
#define ROBOTMAP_H

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */

// For example to map the left and right motors, you could define the
// following variables to use with your drivetrain subsystem.
// constexpr int LEFTMOTOR = 1;
// constexpr int RIGHTMOTOR = 2;

// If you are using multiple modules, make sure to define both the port
// number and the module. For example you with a rangefinder:
// constexpr int RANGE_FINDER_PORT = 1;
// constexpr int RANGE_FINDER_MODULE = 1;

//Drive Constants
const int FRONT_LEFT_DRIVE_PORT = 9;
const int BACK_LEFT_DRIVE_PORT = 2;
const int FRONT_RIGHT_DRIVE_PORT = 3;
const int BACK_RIGHT_DRIVE_PORT = 4;

const int DRIVE_SHIFTER_PORT_A = 0;
const int DRIVE_SHIFTER_PORT_B = 1;

const float DRIVE_DEADZONE = .05;

//Lift Constants
const int RIGHT_LIFT_MOTOR_PORT = 6;
const int LEFT_LIFT_MOTOR_PORT = 7;

const int RIGHT_LIFT_SWITCH_PORT = 0;
const int LEFT_LIFT_SWITCH_PORT = 1;

//Gear Constants
const int DUSTPAN_PORT_A = 2;
const int DUSTPAN_PORT_B = 3;

const int TRAPDOOR_PORT_A = 4;
const int TRAPDOOR_PORT_B = 5;

const int RIGHT_PLATE_PORT = 0;
const int LEFT_PLATE_PORT = 1;

#endif  // ROBOTMAP_H
