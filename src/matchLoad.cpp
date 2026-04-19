#include "globals.hpp"

namespace matchLoad {

        bool loaderState1 = false;

        void daemon(){
            while(true){
                loaderPiston.set_value(loaderState1);
                pros::delay(20);
            }
        }

        void toggle(bool target){
            loaderState1 = target;
        }

        void toggle(){
            loaderState1 = !loaderState1;
        }

        void out(){
            toggle(true);
        }

        void in(){
            toggle(false);
        }
}