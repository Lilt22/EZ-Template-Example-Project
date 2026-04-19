#include "globals.hpp"
#include "pros/rtos.hpp"

namespace lever{

    
    void daemon();

    void spinAt(int speed);

    void on();

    void off();

    void reverse();
    
    void score();

    void stopScoring();

    void toggle(bool targ);

    void toggle();

    void up();

    void down();

    void scoreSlow();

    void stopScoringSlow();

    void setLimit(double lim);

    void setManual(bool targ);

}

