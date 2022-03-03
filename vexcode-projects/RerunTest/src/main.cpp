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

int8_t autonData[5][250];

//rerun variables
bool liftIsUp;
bool liftIsDown;
bool forkliftIsUp;
bool forkliftIsDown;
bool pnuExtend;
bool pastPnu = false;
int8_t liftInput = 0;
int8_t forkLiftInput = 0;
int8_t pnuInput = 0;




bool cardIn = false;
bool reverseMode = false;
bool platformMode = false;
int deadzone = 15;
bool pEx = false;
int8_t axis3 = 0;
int8_t axis1 = 0;
int8_t leftMotorSpeed = 0;
int8_t rightMotorSpeed = 0;

int counter = 0;
int rerunCounter = 0;



//Stuff like calibrating sensors, positioning lift, etc.
void setup (void) {


}


//User control period (and general)
int main() {

  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // if (Brain.SDcard.isInserted()){
  //   cardIn = true;
  // }
  cardIn = true;
  
  // infinite loop for the controller binds
  while (Brain.timer(sec) < 5 && cardIn) {  
    bool liftIsUp = false;
    bool liftIsDown = false;
    bool forkliftIsUp = false;
    bool forkliftIsDown = false;
    

    //Pnuematics code
    if (Yeetroller.ButtonA.pressing()){
      counter++;
      if (counter == 1){
        pEx = !pEx;
        p1.set(pEx);
        p2.set(pEx);
      }
      this_thread::sleep_for(200);
    }
  
    /*
    * DRIVETRAIN CALCULATIONS
    */

    //getting controller values
    axis3 = Yeetroller.Axis3.position();
    axis1 = Yeetroller.Axis1.position();




    //reverse mode calculations
    if (Yeetroller.ButtonX.pressing()){
      reverseMode = !reverseMode;
      if (reverseMode){
        printTextCont("Reverse Mode: ON", 1);
      } else {
        printTextCont("Reverse Mode: OFF", 1);
      }
      this_thread::sleep_for(400);
    }
    if (reverseMode){
      axis3 = -axis3;
    }




    //platform mode
    if (Yeetroller.ButtonY.pressing()){
      platformMode = !platformMode;
      if (platformMode){
        printTextCont("Platform Mode: ON", 10);
      } else {
        printTextCont("Platform Mode: OFF", 10);
      }
      this_thread::sleep_for(400);
    }
    

  

    /*
    * calculating speed
    */
    // Get the velocity percentage of the left motor. (Axis3 + Axis1)
    leftMotorSpeed =  axis3 + axis1;
    // Get the velocity percentage of the right motor. (Axis3 - Axis1)
    rightMotorSpeed = axis3 - axis1;




    //Deadzone calculations
    if (abs(leftMotorSpeed) < deadzone){
      leftMotorSpeed = 0;
    }
    if (abs(rightMotorSpeed) < deadzone){
      rightMotorSpeed = 0;
    }




    //DRIVETRAIN CODE

    if (platformMode){
      if (leftMotorSpeed == 0 && rightMotorSpeed == 0){
        leftDriveMotor.stop(vex::brakeType::hold);
        rightDriveMotor.stop(vex::brakeType::hold);
        leftDriveMotor2.stop(vex::brakeType::hold);
        rightDriveMotor2.stop(vex::brakeType::hold);

      } else {
        leftDriveMotor.spin(vex::directionType::fwd, leftMotorSpeed, vex::velocityUnits::pct);
        leftDriveMotor2.spin(vex::directionType::fwd, leftMotorSpeed, vex::velocityUnits::pct);
        rightDriveMotor.spin(vex::directionType::fwd, rightMotorSpeed, vex::velocityUnits::pct);
        rightDriveMotor2.spin(vex::directionType::fwd, rightMotorSpeed, vex::velocityUnits::pct);
      }
    } else {
      leftDriveMotor.spin(vex::directionType::fwd, leftMotorSpeed, vex::velocityUnits::pct);
      leftDriveMotor2.spin(vex::directionType::fwd, leftMotorSpeed, vex::velocityUnits::pct);
    

      rightDriveMotor.spin(vex::directionType::fwd, rightMotorSpeed, vex::velocityUnits::pct);
      rightDriveMotor2.spin(vex::directionType::fwd, rightMotorSpeed, vex::velocityUnits::pct);
    }
    


    //4-BAR CODE

    if (Yeetroller.ButtonR2.pressing() ) {
      leftLift.spin(vex::directionType::fwd, 80, vex::velocityUnits::pct);
      rightLift.spin(vex::directionType::fwd, 80, vex::velocityUnits::pct);
      liftIsUp = true;
    }
    else if (Yeetroller.ButtonR1.pressing()){
      leftLift.spin(vex::directionType::rev, 80, vex::velocityUnits::pct);
      rightLift.spin(vex::directionType::rev, 80, vex::velocityUnits::pct);
      liftIsDown = true;
    }
    else {
      leftLift.stop(vex::brakeType::brake);
      rightLift.stop(vex::brakeType::brake);
      liftIsUp = false;
      liftIsDown = false;

    }



    //FORKLIFT CODE

    if (Yeetroller.ButtonL2.pressing() ) {
      forkliftLeft.spin(vex::directionType::fwd, 75, vex::velocityUnits::pct);
      forkliftRight.spin(vex::directionType::fwd, 75, vex::velocityUnits::pct);
      forkliftIsUp = true;
    }
    else if (Yeetroller.ButtonL1.pressing()){
      forkliftLeft.spin(vex::directionType::rev, 75, vex::velocityUnits::pct);
      forkliftRight.spin(vex::directionType::rev, 75, vex::velocityUnits::pct);
      forkliftIsDown = true;
    }
    else {
      forkliftLeft.stop(vex::brakeType::brake);
      forkliftRight.stop(vex::brakeType::brake);
      forkliftIsDown = false;
      forkliftIsUp = false;
    }



    //calculations
    if (liftIsUp == true){
      liftInput = 2;
    } else if (liftIsDown == true){
      liftInput = 1;
    } else if (liftIsDown == false && liftIsUp == false){
      liftInput = 0;
    }

    if (forkliftIsUp == true){
      forkLiftInput = 2;
    } else if (forkliftIsDown == true){
      forkLiftInput = 1;
    } else if (forkliftIsUp == false && forkliftIsDown == false){
      forkLiftInput = 0;
    }

    if (pEx == true){
      pnuInput = 1;
    } else {
      pnuInput = 0;
    }


    autonData[0][rerunCounter] = leftMotorSpeed + 100;
    autonData[1][rerunCounter] = rightMotorSpeed + 100;
    autonData[2][rerunCounter] = liftInput;
    autonData[3][rerunCounter] = forkLiftInput;
    autonData[4][rerunCounter] = pnuInput;
    rerunCounter++;

    
    wait(20,msec);
    counter = 0;
  }

  while (1){
    if (Yeetroller.ButtonA.pressing()){
      counter++;
      if (counter == 1){
        pEx = !pEx;
        p1.set(pEx);
        p2.set(pEx);
      }
    }
      this_thread::sleep_for(200);

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


    if (Yeetroller.ButtonUp.pressing()){
      for (int i = 0; i < 250; i++){
        leftMotorSpeed = autonData[0][i];
        rightMotorSpeed = autonData[1][i];
        liftInput = autonData[2][i];
        forkLiftInput = autonData[3][i];
        pnuInput = autonData[4][i];


        leftDriveMotor.spin(vex::directionType::fwd, leftMotorSpeed - 100, vex::velocityUnits::pct);
        leftDriveMotor2.spin(vex::directionType::fwd, leftMotorSpeed - 100, vex::velocityUnits::pct);
        rightDriveMotor.spin(vex::directionType::fwd, rightMotorSpeed - 100, vex::velocityUnits::pct);
        rightDriveMotor2.spin(vex::directionType::fwd, rightMotorSpeed - 100, vex::velocityUnits::pct);


        if (liftInput == 2){
          leftLift.spin(vex::directionType::fwd, 80, vex::velocityUnits::pct);
          rightLift.spin(vex::directionType::fwd, 80, vex::velocityUnits::pct);
        } else if (liftInput == 1){
          leftLift.spin(vex::directionType::rev, 80, vex::velocityUnits::pct);
          rightLift.spin(vex::directionType::rev, 80, vex::velocityUnits::pct);
        } else if (liftInput == 0){
          leftLift.stop(vex::brakeType::brake);
          rightLift.stop(vex::brakeType::brake);
        }

        if (forkLiftInput == 2){
          leftLift.spin(vex::directionType::fwd, 80, vex::velocityUnits::pct);
          rightLift.spin(vex::directionType::fwd, 80, vex::velocityUnits::pct);
        } else if (forkLiftInput == 1){
          leftLift.spin(vex::directionType::rev, 80, vex::velocityUnits::pct);
          rightLift.spin(vex::directionType::rev, 80, vex::velocityUnits::pct);
        } else if (forkLiftInput == 0){
          leftLift.stop(vex::brakeType::brake);
          rightLift.stop(vex::brakeType::brake);
        }


      }
    }
  }
}