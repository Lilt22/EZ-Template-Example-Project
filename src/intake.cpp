#include "globals.hpp"
#include "pros/rtos.hpp"

namespace intake{

    int intkSpeed = 0;
   

    void daemon(){

        while(true){
            
            intkMtr.move_voltage(intkSpeed);
            
            pros::delay(10);
        }
    }

    void spinAt(int speed){
        intkSpeed = speed;
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

    int getSpeed(){
        return intkSpeed;
    }

}

