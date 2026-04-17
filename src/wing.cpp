#include "globals.hpp"
#include "pros/adi.h"
#include "pros/rtos.hpp"

namespace wing {

    bool target = false;

    void daemon(){
        while(true){
            wingPiston.set_value(target);
            
            pros::delay(20);
        }
    }
    
    void toggle(bool targ){
        target = targ;
    }

    void toggle(){
        target = !target;
    }

    void out(){
        toggle(true);
    }

    void in(){
        toggle(false);
    }

    
}