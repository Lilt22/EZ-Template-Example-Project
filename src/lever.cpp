#include "globals.hpp"
#include "pros/motors.h"
#include "pros/rtos.hpp"
#include "intake.hpp"

namespace lever{

    int leverSpeed = 0;

    bool elevatorState = false;

    bool isScoring = false;

    bool hoodState = false;

    double downAng = 149;

    double targ = downAng;

    double limit = 334;

    double pos;
    
    double kP = 500;

    bool isScoringSlow = false;

    int intkSaveState = 0;

    bool manual = false;

    void daemon(){


        while(true){

            if(leverEncoder.get_angle() / 100 > 171 && intake::getSpeed() != -11999){
                intkSaveState = intake::getSpeed();
                intake::spinAt(-11999);
            } else if(intake::getSpeed() == -11999 && leverEncoder.get_angle() / 100 < 171){
                intake::spinAt(intkSaveState);
            }
            
            
            if(!isScoring && !isScoringSlow){
                
                
                pos = leverEncoder.get_angle() / 100.0;

                double error = pos - targ;
                

                leverMtr.move_voltage(-kP * error);

                hoodState = false;


            
            
            } else if (isScoring) {

                if(leverEncoder.get_angle() / 100.0 < limit){
                    leverMtr.move_voltage(12000);
                } else {
                    leverMtr.move_voltage(0);
                }
               

                

                hoodState = true;

            } else {
                if(!elevatorState){
                    if(leverEncoder.get_angle() / 100.0 < limit){
                        leverMtr.move_voltage(7000);
                    } else {
                        leverMtr.move_voltage(0);
                    }
                } else {
                    if(leverEncoder.get_angle() / 100.0 < limit){
                        leverMtr.move_voltage(9500);
                    } else {
                        leverMtr.move_voltage(0);
                    }
                }
                
               

                
                
                    hoodState = true;
                
                
            }

            if(manual){
                hoodState = true;
            }
                

            leverElevatorPiston.set_value(elevatorState);

            hoodPiston.set_value(hoodState);
            
            pros::delay(10);
        }
    }

    void spinAt(int speed){
        leverSpeed = speed;
    }

    void on(){
        spinAt(12000);
    }

    void off(){
        spinAt(0);
    }

    void reverse(){
        spinAt(-12000);
    }

    void score(){
        isScoring = true;
    }

    void stopScoring(){
        isScoring = false;
    }

    void scoreSlow(){
        isScoringSlow = true;
    }

    void stopScoringSlow(){
        isScoringSlow = false;
    }

    void toggle(bool targ){
        elevatorState = targ;
    }

    void toggle(){
        elevatorState = !elevatorState;
    }

    void up(){
        toggle(true);
    }

    void down(){
        toggle(false);
    }

    void toggleHood(bool targ){
        hoodState = targ;
    }

    void toggleHood(){
        hoodState = !hoodState;
    }

    void open(){
        toggle(true);
    }

    void close(){
        toggle(false);
    }

    void setLimit(double lim){
        limit = lim;
    }

    void setManual(bool targ){
        manual = targ;
    }

}
