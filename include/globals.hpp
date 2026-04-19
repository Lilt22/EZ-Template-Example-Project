#include "api.h"
#include "pros/adi.hpp"
#include "pros/rotation.hpp"
#include <vector>

//First Stage Intake Motor
extern pros::Motor intkMtr;

//Long Goal Descore Piston
extern pros::adi::DigitalOut wingPiston;

//IMU
extern int IMU1Port;

//IMU
extern int IMU2Port;

//Tongue Mech Piston
extern pros::adi::DigitalOut loaderPiston;

//Left Odom Wheel Sensor
extern pros::Rotation leverEncoder;

extern pros::adi::DigitalOut trackingDeployPiston;

//Right Odom Wheel Sensor
extern pros::Rotation vertSens;

// //List of left drive ports
// extern std::vector<std::int8_t> leftDrivePorts;

// //List of right drive ports
// extern std::vector<std::int8_t> rightDrivePorts;

extern pros::Optical firstSens;

extern pros::Optical secondSens;

extern pros::Motor leverMtr;

extern pros::adi::DigitalOut hoodPiston;

extern pros::adi::DigitalOut leverElevatorPiston;

extern pros::Distance localXSens;

extern pros::Distance localYSens;

extern pros::adi::DigitalOut lowScorePiston;

extern pros::MotorGroup leftMtrs;
extern pros::MotorGroup rightMtrs;
