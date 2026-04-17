#include "globals.hpp"

namespace lowScore {

        bool pistonState = false;

        void daemon(){
            while(true){
                lowScorePiston.set_value(pistonState);
                pros::delay(20);
            }
        }

        void toggle(bool target){
            pistonState = target;
        }

        void toggle(){
            pistonState = !pistonState;
        }

        void out(){
            toggle(true);
        }

        void in(){
            toggle(false);
        }
}