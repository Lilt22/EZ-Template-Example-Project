#include "EZ-Template/util.hpp"
#include "main.h"
#include "pros/device.hpp"
#include "pros/rtos.hpp"
#include "subsystems.hpp"

/////
// For installation, upgrading, documentations, and tutorials, check out our website!
// https://ez-robotics.github.io/EZ-Template/
/////

// These are out of 127
const int DRIVE_SPEED = 110;
const int TURN_SPEED = 90;
const int SWING_SPEED = 110;

///
// Constants
///
void default_constants() {
  // P, I, D, and Start I
  chassis.pid_drive_constants_set(25, 0.0, 180);         // Fwd/rev constants, used for odom and non odom motions
  chassis.pid_heading_constants_set(10, 0.0, 0);        // Holds the robot straight while going forward without odom
  chassis.pid_turn_constants_set(12.0, 0.05, 100, 15.0);     // Turn in place constants
  chassis.pid_swing_constants_set(6.0, 0.0, 65.0);           // Swing constants
  chassis.pid_odom_angular_constants_set(6.5, 0.0, 52.5);    // Angular control for odom motions
  chassis.pid_odom_boomerang_constants_set(5.8, 0.0, 32.5);  // Angular control for boomerang motions

  // Exit conditions
  chassis.pid_turn_exit_condition_set(100_ms, 2_deg, 250_ms, 2_deg, 500_ms, 500_ms);
  chassis.pid_swing_exit_condition_set(100_ms, 3_deg, 250_ms, 7_deg, 500_ms, 500_ms);
  chassis.pid_drive_exit_condition_set(100_ms, 1_in, 250_ms, 1_in, 500_ms, 500_ms);
  chassis.pid_odom_turn_exit_condition_set(100_ms, 2_deg, 250_ms, 2_deg, 500_ms, 750_ms);
  chassis.pid_odom_drive_exit_condition_set(100_ms, 1_in, 250_ms, 1_in, 500_ms, 750_ms);
  chassis.pid_turn_chain_constant_set(3_deg);
  chassis.pid_swing_chain_constant_set(5_deg);
  chassis.pid_drive_chain_constant_set(3_in);

  // Slew constants
  chassis.slew_turn_constants_set(3_deg, 70);
  chassis.slew_drive_constants_set(7_in, 70);
  chassis.slew_swing_constants_set(3_in, 80);

  // The amount that turns are prioritized over driving in odom motions
  // - if you have tracking wheels, you can run this higher.  1.0 is the max
  chassis.odom_turn_bias_set(0.9);

  chassis.odom_look_ahead_set(7_in);           // This is how far ahead in the path the robot looks at
  chassis.odom_boomerang_distance_set(16_in);  // This sets the maximum distance away from target that the carrot point can be
  chassis.odom_boomerang_dlead_set(0.625);     // This handles how aggressive the end of boomerang motions are

  chassis.pid_angle_behavior_set(ez::shortest);  // Changes the default behavior for turning, this defaults it to the shortest path there
}

///
// Drive Example
///

void move(int left, int right){
  leftMtrs.move_voltage(left);
  rightMtrs.move_voltage(right);
}

void soloAWP(){

  

    chassis.odom_xyt_set(16_in, -46.5_in, 270_deg); 
		intake::on();
		wing::toggle(true);
	// 	move(12000, 12000);
	// 	pros::delay(100);
	// 	move(00, 00);
  // pros::delay(200);
   chassis.pid_odom_set({{46.7_in, -46.5_in}, rev, DRIVE_SPEED},
      true); 
    chassis.pid_wait();
	  lever::toggle();
		matchLoad::toggle();
	chassis.pid_turn_set(180, TURN_SPEED);
  pros::delay(450);
		chassis.pid_odom_set({{47.3_in, -57_in},fwd, DRIVE_SPEED},
                        false);
		pros::delay(1050);
		 chassis.pid_odom_set({{47.2_in, -27_in}, rev, DRIVE_SPEED},
                        true);

	  pros::delay(300);
    matchLoad::toggle();
    pros::delay(650);
    
		
	  
    chassis.pid_odom_set({{48.5_in, -30_in}, rev, 0}, true);
    pros::delay(300);
    lever::score();
    pros::delay(1000);
    lever::stopScoring();

     chassis.pid_odom_set({{48.5_in, -44_in}, fwd, 70});
     chassis.pid_wait();
     chassis.pid_turn_set(325, TURN_SPEED);
     pros::delay(400);


  

    chassis.pid_odom_set({ 
      {{28_in, -25_in}, fwd, DRIVE_SPEED},
                      {{-18_in, -25_in}, fwd, DRIVE_SPEED},
                       {{-46.5_in, -42_in}, fwd, DRIVE_SPEED}},
                      false);

    pros::delay(2500);
    matchLoad::toggle();


  chassis.pid_wait();
  matchLoad::toggle();
  
		
	chassis.pid_turn_set(180, TURN_SPEED);
  chassis.pid_wait();
 
      chassis.pid_odom_set({{-46.5_in, -32_in}, rev, DRIVE_SPEED},
                        false);
      lever::setLimit(225);
      pros::delay(670);
      lever::score();
      chassis.pid_odom_set({{-46.5_in, -30_in}, rev, 0},
                        false);
      pros::delay(900);
      lever::stopScoring();
      lever::setLimit(337);
      chassis.pid_odom_set({{-46.5_in, -47_in}, fwd, DRIVE_SPEED},
                        false);
      chassis.pid_wait();
      lever::toggle();

      chassis.pid_odom_set({{-13_in, -18.5_in}, rev, DRIVE_SPEED},
                        false);
      pros::delay(1100);
      lever::scoreSlow();

}

void leftSplitMID(){
   chassis.odom_xyt_set(-17_in, -53_in, 0_deg); 
		intake::on();
		wing::toggle(true);
    chassis.pid_odom_set({{{-24_in, -22_in}, fwd, DRIVE_SPEED}, 
      {{-47_in, -47_in}, fwd, 110}}, true);

    pros::delay(800);
    matchLoad::toggle();
    chassis.pid_wait();
    chassis.pid_turn_set(180, TURN_SPEED);
    lever::toggle();
    pros::delay(400);
    chassis.pid_odom_set({{-47, -20}, rev, DRIVE_SPEED}, false);
    pros::delay(500);
    chassis.pid_odom_set({{-47_in, -20_in}, rev, 0}, true);
    pros::delay(200);
    lever::score();
    pros::delay(700);
    lever::stopScoring();
    chassis.pid_odom_set({{-46_in, -62_in}, fwd, DRIVE_SPEED}, true);
    pros::delay(1700);
    chassis.pid_odom_set({{-46, -30}, rev, DRIVE_SPEED}, true);
    pros::delay(250);
    lever::toggle();
    chassis.pid_odom_set({{-10.5, -18.5}, rev, DRIVE_SPEED}, true);
    chassis.pid_wait();
    chassis.pid_turn_set(225, DRIVE_SPEED);
    chassis.pid_wait();
    lever::scoreSlow();
    pros::delay(1100);
    chassis.pid_odom_set({{-14, -24}, fwd, DRIVE_SPEED}, true);
    //pros::delay(100);
    chassis.pid_wait();
    lever::toggle();
    lever::stopScoringSlow();
    pros::delay(300);
     chassis.pid_odom_set({{-8, -18}, rev, DRIVE_SPEED}, true);
    //chassis.pid_wait();
}

void leftSplitLONG(){
  chassis.odom_xyt_set(-17_in, -53_in, 0_deg); 
		intake::on();
		wing::toggle(true);
    chassis.pid_odom_set({{{-24_in, -22_in}, fwd, DRIVE_SPEED}, 
      {{-47_in, -47_in}, fwd, 110}}, true);

    pros::delay(800);
    matchLoad::toggle();
    chassis.pid_wait();
    chassis.pid_turn_set(180, TURN_SPEED);
    lever::toggle();
    pros::delay(400);
    chassis.pid_odom_set({{-47, -20}, rev, DRIVE_SPEED}, false);
    pros::delay(500);
    chassis.pid_odom_set({{-47_in, -20_in}, rev, 0}, true);
    pros::delay(200);
    lever::score();
    pros::delay(700);
    lever::stopScoring();
    chassis.pid_odom_set({{-46_in, -64_in}, fwd, DRIVE_SPEED}, true);
    pros::delay(1700);
    chassis.pid_odom_set({{-46, -30}, rev, DRIVE_SPEED}, true);
    pros::delay(250);
    lever::toggle();
    chassis.pid_odom_set({{-12, -18.5}, rev, DRIVE_SPEED}, true);
    chassis.pid_wait();
    chassis.pid_turn_set(225, DRIVE_SPEED);
    chassis.pid_wait();
    lever::scoreSlow();
    pros::delay(1100);
    matchLoad::toggle();
    chassis.pid_odom_set({{-34.5, -42}, fwd, DRIVE_SPEED}, true);
    //pros::delay(100);
    chassis.pid_wait();
    lever::toggle();
    lever::stopScoringSlow();

    chassis.pid_turn_set(180, TURN_SPEED);
    chassis.pid_wait();
    wing::toggle();
    chassis.pid_odom_set({{-34.5, -15.3}, rev, DRIVE_SPEED}, true);
    pros::delay(600);
    chassis.pid_odom_set({{-35, -15.3}, rev, DRIVE_SPEED}, true);
    
    chassis.pid_wait();

}

void rightSplit(){
    chassis.odom_xyt_set(17_in, -53_in, 0_deg); 
		intake::on();
		wing::toggle(true);
    chassis.pid_odom_set({{{24_in, -22_in}, fwd, DRIVE_SPEED}, 
      {{48_in, -47_in}, fwd, 110}}, true);

    pros::delay(800);
    matchLoad::toggle();
    chassis.pid_wait();
    chassis.pid_turn_set(180, TURN_SPEED);
    lever::toggle();
    pros::delay(400);
    chassis.pid_odom_set({{48, -26}, rev, DRIVE_SPEED}, false);
    pros::delay(700);
    chassis.pid_odom_set({{48_in, -20_in}, rev, 0}, true);
    lever::score();
    pros::delay(700);
    lever::stopScoring();
    chassis.pid_odom_set({{47_in, -64_in}, fwd, DRIVE_SPEED}, true);
    pros::delay(1700);
    chassis.pid_odom_set({{47, -50}, rev, DRIVE_SPEED}, true);
    pros::delay(250);
    chassis.pid_wait();
    chassis.pid_turn_set(315, TURN_SPEED);
      chassis.pid_wait();
      matchLoad::toggle();
    chassis.pid_odom_set({{17, -18}, fwd, DRIVE_SPEED}, true);
    chassis.pid_wait();
    chassis.pid_turn_set(315, TURN_SPEED);
      chassis.pid_wait();

      lowScore::toggle(true);
    intake::reverse();
    chassis.pid_drive_set(-3, DRIVE_SPEED);
    chassis.pid_wait();
    chassis.pid_drive_set(4, DRIVE_SPEED);
    chassis.pid_wait();
    chassis.pid_drive_set(-3, DRIVE_SPEED);
    chassis.pid_wait();
    chassis.pid_drive_set(3, DRIVE_SPEED);
    chassis.pid_wait();
    chassis.pid_drive_set(-3, DRIVE_SPEED);
    chassis.pid_wait();
    chassis.pid_drive_set(3, DRIVE_SPEED);
    chassis.pid_wait();
    pros::delay(600);
    chassis.pid_odom_set({{36.5, -42}, rev, DRIVE_SPEED}, true);
    chassis.pid_wait();
    

    chassis.pid_turn_set(0, TURN_SPEED);
    chassis.pid_wait();
    wing::toggle();
    

}

void rightRush(){
  chassis.odom_xyt_set(17_in, -53_in, 0_deg); 
		intake::on();
		wing::toggle(true);
    chassis.pid_odom_set({{{24_in, -22_in}, fwd, DRIVE_SPEED}, 
      {{48_in, -47_in}, fwd, 110}}, true);

    pros::delay(900);
    matchLoad::toggle();
    chassis.pid_wait();
    chassis.pid_turn_set(180, TURN_SPEED);
    lever::toggle();
    pros::delay(400);
    chassis.pid_odom_set({{48, -26}, rev, DRIVE_SPEED}, false);
    pros::delay(700);
    chassis.pid_odom_set({{48_in, -20_in}, rev, 0}, true);
    lever::score();
    pros::delay(700);
    lever::stopScoring();
    matchLoad::toggle();
    chassis.pid_odom_set({{47_in, -45_in}, fwd, DRIVE_SPEED}, true);
    
    chassis.pid_wait();

    chassis.pid_turn_set(325, TURN_SPEED);
    chassis.pid_wait();
    chassis.pid_odom_set({{{40.5_in, -42_in}, fwd, DRIVE_SPEED}, {{40.5_in, -15_in}, fwd, DRIVE_SPEED}}, true);
    pros::delay(600);
    wing::toggle();
}