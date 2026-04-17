#include "api.h"
#include "pros/adi.hpp"
#include "pros/motors.hpp"
#include "pros/optical.hpp"
#include "subsystems.hpp"

//First Stage Intake Motor
pros::Motor intkMtr(-2);

//Long Goal Descore Piston
pros::adi::DigitalOut wingPiston('A');


//IMU
int IMU1Port = 11;

//IMU
int IMU2Port = 12;

//Tongue Mech Piston
pros::adi::DigitalOut loaderPiston('D');

pros::adi::DigitalOut hoodPiston('C');

pros::adi::DigitalOut trackingDeployPiston('E');

pros::adi::DigitalOut leverElevatorPiston('B');

//Left Odom Wheel Sensor
pros::Rotation leverEncoder(7);

//Right Odom Wheel Sensor
pros::Rotation vertSens(-18);

//List of left drive ports

//std::vector<std::int8_t> leftDrivePorts = {-5, 4, -13};

//List of right drive ports
//std::vector<std::int8_t> rightDrivePorts = {9, 8, -17};

pros::Optical firstSens(17);

pros::Optical secondSens(17);

pros::Motor leverMtr(10);

pros::Distance localXSens(14);

pros::Distance localYSens(15);

pros::adi::DigitalOut lowScorePiston('F');
