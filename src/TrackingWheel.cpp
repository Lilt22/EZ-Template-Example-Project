#include "api.h"
#include <array>
#include "TrackingWheel.hpp"


    /*
    Converts degrees to radians
    */
    double TrackingWheel::degToRad(double deg){
        return deg * M_PI/180;
    }

    /*
    Converts radians to degrees
    */
    double TrackingWheel::radToDeg(double rad){
        return rad * 180/M_PI;
    }

    /*
    Converts sensor ticks (centidegrees) to inches moved
    */
    double TrackingWheel::ticksToInches(double ticks){
        //36000 ticks per rotation in the sensors

        double ticksPerInch = (36000 / (wheelDiameter * M_PI)) * (23.1/24.0);

        return ticks / ticksPerInch;

    }


    TrackingWheel::TrackingWheel(pros::Rotation* sensor, double distFromCenter, double diameter, double angle){
        perpindicularDistFromCenter = distFromCenter;
        wheelDiameter = diameter;
        theta = angle;
        wheel = sensor;
        wheel->reset();   
        lastWheelTicks = wheel->get_position();
    }

    /*
    Returns a 2D vector of the last cycles wheel movement accounting for the delta heading as an argument
    */
    std::array<double, 2> TrackingWheel::getCycleVector(double deltaHeading){
        double currentTicks = wheel->get_position();
        double magnitude = ticksToInches(currentTicks - lastWheelTicks) - ((radToDeg(deltaHeading) / 360) * 2 * perpindicularDistFromCenter * M_PI);
        std::array<double, 2> localCords = {cos(degToRad(theta)) * magnitude, sin(degToRad(theta)) * magnitude};
        lastWheelTicks = currentTicks;
        return localCords;
    }


