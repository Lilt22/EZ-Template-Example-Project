#include "globals.hpp"

namespace matchLoad {

        bool loaderState = false;

        void daemon(){
            while(true){
                loaderPiston.set_value(loaderState);
                pros::delay(20);
            }
        }

        void toggle(bool target){
            loaderState = target;
        }

        void toggle(){
            loaderState = !loaderState;
        }

        void out(){
            toggle(true);
        }

        void in(){
            toggle(false);
        }
}