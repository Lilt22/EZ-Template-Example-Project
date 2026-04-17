#include "api.h"
#include <array>

class TrackingWheel{

     private:


        //Rotation center of the wheel
        pros::Rotation* wheel;

        //Ticks on the wheel as of the last cycle
        

        //As it sounds
        double perpindicularDistFromCenter;

        //Diameter of the wheel on the tracking sensor
        double wheelDiameter;

        // wheel angle in degrees
        double theta;

        /*
        Converts degrees to radians
        */
        double degToRad(double deg);

        /*
        Converts radians to degrees
        */
        double radToDeg(double rad);

        /*
        Converts sensor ticks (centidegrees) to inches moved
        */
        double ticksToInches(double ticks);

  
    public:

        double lastWheelTicks;

        /*
        Constructor taking in the rotation sensor object, the wheel's perpendicular distance from the robot tracking center, the diameter of the wheel, and the angle of the wheel in degrees
        */
        TrackingWheel(pros::Rotation* sensor, double distFromCenter, double diameter, double angle);

        /*
        Returns a 2D vector of the last cycles wheel movement accounting for the delta heading as an argument
        */
        std::array<double, 2> getCycleVector(double deltaHeading);

};