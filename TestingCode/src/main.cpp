/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       pranavakella                                              */
/*    Created:      Friday June 11 2021                                       */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// ---- END VEXCODE CONFIGURED DEVICES ----




// Import Statements
#include "vex.h"

#include <string>

//Field definition
using namespace vex;

vex::competition    Competition;

bool aPressed = false;
int deadzone = 15;
bool pEx = false;

int counter = 0;



//Stuff like calibrating sensors, positioning lift, etc.
void setup (void) {


}


//User control period (and general)
int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  
  
  // infinite loop for the controller binds
  while (1) {  

    if (Yeetroller.ButtonA.pressing()){
      counter++;
      if (counter == 1 ){
        pEx = !pEx;
        p1.set(pEx);
        p2.set(pEx);
      }
      
    }
  
    //DRIVETRAIN CALCULATIONS


    //measuring values
    // Get the velocity percentage of the left motor. (Axis3 + Axis1)
    int leftMotorSpeed =  Yeetroller.Axis3.position() + Yeetroller.Axis1.position();
    // Get the velocity percentage of the right motor. (Axis3 - Axis1)
    int rightMotorSpeed = Yeetroller.Axis3.position() - Yeetroller.Axis1.position();

    //Deadzone calculations
    if (abs(leftMotorSpeed) < deadzone){
      leftMotorSpeed = 0;
    }
    if (abs(rightMotorSpeed) < deadzone){
      rightMotorSpeed = 0;
    }
    


    //DRIVETRAIN CODE


    leftDriveMotor.spin(vex::directionType::fwd, leftMotorSpeed, vex::velocityUnits::pct);
    leftDriveMotor2.spin(vex::directionType::fwd, leftMotorSpeed, vex::velocityUnits::pct);
   

    rightDriveMotor.spin(vex::directionType::fwd, rightMotorSpeed, vex::velocityUnits::pct);
    rightDriveMotor2.spin(vex::directionType::fwd, rightMotorSpeed, vex::velocityUnits::pct);
    


    //4-BAR CODE

    if (Yeetroller.ButtonR2.pressing() ) {
      leftLift.spin(vex::directionType::fwd, 80, vex::velocityUnits::pct);
      rightLift.spin(vex::directionType::fwd, 80, vex::velocityUnits::pct);

    }
    else if (Yeetroller.ButtonR1.pressing()){
      leftLift.spin(vex::directionType::rev, 80, vex::velocityUnits::pct);
      rightLift.spin(vex::directionType::rev, 80, vex::velocityUnits::pct);
    }
    else {
      leftLift.stop(vex::brakeType::brake);
      rightLift.stop(vex::brakeType::brake);

    }



    //FORKLIFT CODE

    if (Yeetroller.ButtonL2.pressing() ) {
      forkliftLeft.spin(vex::directionType::fwd, 75, vex::velocityUnits::pct);
      forkliftRight.spin(vex::directionType::fwd, 75, vex::velocityUnits::pct);
    }
    else if (Yeetroller.ButtonL1.pressing()){
      forkliftLeft.spin(vex::directionType::rev, 75, vex::velocityUnits::pct);
      forkliftRight.spin(vex::directionType::rev, 75, vex::velocityUnits::pct);
    }
    else {
      forkliftLeft.stop(vex::brakeType::brake);
      forkliftRight.stop(vex::brakeType::brake);
    }

    

    
    

    
    wait(20,msec);
    counter = 0;
  }
}