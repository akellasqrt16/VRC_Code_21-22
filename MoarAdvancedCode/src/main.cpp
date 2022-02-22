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
vex::brain    Brain;
vex::competition    Competition;



//Motor setup
//Make sure to CHANGE THE PORT NUMBER TO THE PORT THAT THE CORRESPONDING MOTOR IS PLUGGED INTO


//Drivetrain
vex::motor  leftDriveMotor = vex::motor( vex:: PORT4, true);
vex::motor  rightDriveMotor = vex::motor( vex:: PORT7);

//Lift motors (4 Bar)
vex::motor  leftDriveMotor2 = vex::motor( vex:: PORT13, true);
vex::motor  rightDriveMotor2 = vex::motor( vex:: PORT5);



//Motors of the forklift in the back
vex::motor  forkliftLeft = vex::motor( vex:: PORT9, true);
vex::motor  forkliftRight = vex::motor( vex:: PORT20);

//lift motors
vex::motor  leftLift = vex::motor( vex:: PORT19, true);
vex::motor  rightLift = vex::motor( vex:: PORT14);


//Controller setup
vex::controller Yeetroller = vex::controller();

//Field setup
bool aPressed = false;
int deadzone = 15;
bool pEx = false;

int counter = 0;

//Created functions:
void printMotorValue(int num, int num1) {
  Yeetroller.Screen.clearScreen();
  Yeetroller.Screen.setCursor(1,1);
  Yeetroller.Screen.print(num);
  Yeetroller.Screen.setCursor(1, 15);
  Yeetroller.Screen.print(num1);
}

void printText(const char *str){
  Yeetroller.Screen.clearScreen();
  Yeetroller.Screen.setCursor(1, 1);
  Yeetroller.Screen.print(str);
}




void moveForward(double deg){
  rightDriveMotor.setVelocity(100, percent);
  leftDriveMotor.setVelocity(100, percent);
  leftDriveMotor.startRotateFor(vex::directionType::fwd, deg, vex::rotationUnits::deg);
  rightDriveMotor.rotateFor(vex::directionType::fwd, deg, vex::rotationUnits::deg);
  rightDriveMotor2.setVelocity(100, percent);
  leftDriveMotor2.setVelocity(100, percent);
  leftDriveMotor2.startRotateFor(vex::directionType::fwd, deg, vex::rotationUnits::deg);
  rightDriveMotor2.rotateFor(vex::directionType::fwd, deg, vex::rotationUnits::deg);
}

void moveBackwards(double deg){
  rightDriveMotor.setVelocity(85, percent);
  leftDriveMotor.setVelocity(85, percent);
  leftDriveMotor.startRotateFor(vex::directionType::fwd, deg, vex::rotationUnits::deg);
  rightDriveMotor.rotateFor(vex::directionType::fwd, deg, vex::rotationUnits::deg);
  rightDriveMotor2.setVelocity(85, percent);
  leftDriveMotor2.setVelocity(85, percent);
  leftDriveMotor2.startRotateFor(vex::directionType::fwd, deg, vex::rotationUnits::deg);
  rightDriveMotor2.rotateFor(vex::directionType::fwd, deg, vex::rotationUnits::deg);
}

void turnLeft(double deg){
  rightDriveMotor.setVelocity(85, percent);
  leftDriveMotor.setVelocity(85, percent);
  rightDriveMotor.rotateFor(vex::directionType::rev, deg, vex::rotationUnits::deg);
}

void turnRight(double deg){
  rightDriveMotor.setVelocity(85, percent);
  leftDriveMotor.setVelocity(85, percent);
  leftDriveMotor.rotateFor(vex::directionType::rev, deg, vex::rotationUnits::deg);
}

void turnLeft90(){
  rightDriveMotor.setVelocity(85, percent);
  leftDriveMotor.setVelocity(85, percent);
  rightDriveMotor.rotateFor(vex::directionType::rev, 787.5, vex::rotationUnits::deg);
}

void turnRight90(){
  rightDriveMotor.setVelocity(85, percent);
  leftDriveMotor.setVelocity(85, percent);
  leftDriveMotor.rotateFor(vex::directionType::rev, 787.5, vex::rotationUnits::deg);
}

void standstillTurnRight90(){
  rightDriveMotor.setVelocity(85, percent);
  leftDriveMotor.setVelocity(85, percent);
  leftDriveMotor.startRotateFor(vex::directionType::rev, 787.5, vex::rotationUnits::deg);
  rightDriveMotor.rotateFor(vex::directionType::fwd, 787.5, vex::rotationUnits::deg);
}

void standstillTurnLeft90(){
  rightDriveMotor.setVelocity(85, percent);
  leftDriveMotor.setVelocity(85, percent);
  leftDriveMotor.startRotateFor(vex::directionType::fwd, 787.5, vex::rotationUnits::deg);
  rightDriveMotor.rotateFor(vex::directionType::rev, 787.5, vex::rotationUnits::deg);
}

//void liftUp(double deg){
//  rightLift.setVelocity(100, percent);
//  leftLift.setVelocity(100, percent);
//  leftLift.startRotateFor(vex::directionType::rev, deg, vex::rotationUnits::deg);
//  rightLift.rotateFor(vex::directionType::rev, deg, vex::rotationUnits::deg);
//}

//void liftDown(double deg){
//  rightLift.setVelocity(100, percent);
//  leftLift.setVelocity(100, percent);
//  leftLift.startRotateFor(vex::directionType::fwd, deg, vex::rotationUnits::deg);
//  rightLift.rotateFor(vex::directionType::fwd, deg, vex::rotationUnits::deg);
//}
void forkliftUp(double deg){
  forkliftRight.setVelocity(100, percent);
  forkliftLeft.setVelocity(100, percent);
  forkliftLeft.startRotateFor(vex::directionType::rev, deg, vex::rotationUnits::deg);
  forkliftRight.rotateFor(vex::directionType::rev, deg, vex::rotationUnits::deg);
}
void forkliftDown(double deg){
  forkliftRight.setVelocity(100, percent);
  forkliftLeft.setVelocity(100, percent);
  forkliftLeft.startRotateFor(vex::directionType::fwd, deg, vex::rotationUnits::deg);
  forkliftRight.rotateFor(vex::directionType::fwd, deg, vex::rotationUnits::deg);
}
//230

/* Auton code for the left side
*/

void leftSideAuton(){

}

void rightSideAuton(){
  //move both drivetrain forward and forklift down 
      forkliftLeft.setVelocity(75, percent);
      forkliftRight.setVelocity(100, percent);
      rightDriveMotor.setVelocity(100, percent);
      leftDriveMotor.setVelocity(100, percent);
      leftDriveMotor.spin(vex::directionType::fwd);
      rightDriveMotor.spin(vex::directionType::fwd);
      forkliftLeft.spin(vex::directionType::rev);
      forkliftRight.spin(vex::directionType::rev);
      vex::task::sleep(1300);

      //move drivetrain forward a little bit 
      rightDriveMotor.setVelocity(30, percent);
      leftDriveMotor.setVelocity(30, percent);
      leftDriveMotor.spin(vex::directionType::fwd);
      rightDriveMotor.spin(vex::directionType::fwd);
      vex::task::sleep(100);

      //move forklift up with goal 
      forkliftLeft.spin(vex::directionType::fwd);
      forkliftRight.spin(vex::directionType::fwd);
      vex::task::sleep(1000);
      
      //move backward with goal 
      rightDriveMotor.setVelocity(80, percent);
      leftDriveMotor.setVelocity(80, percent);
      leftDriveMotor.spin(vex::directionType::rev);
      rightDriveMotor.spin(vex::directionType::rev);
      vex::task::sleep(1300);
}

//Stuff like calibrating sensors, positioning lift, etc.
void setup (void) {


}


//User control period (and general)
int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  
  
  // infinite loop for the controller binds
  while (1) {

    digital_out p1 = digital_out(Brain.ThreeWirePort.A);
    digital_out p2 = digital_out(Brain.ThreeWirePort.B);
   

    if (Yeetroller.ButtonA.pressing()){
      counter++;
      if (counter == 1 ){
        pEx = !pEx;
        p1.set(pEx);
        p2.set(pEx);
      }
      
    }
    //measuring values
        // Get the velocity percentage of the left motor. (Axis3 + Axis1)
    int leftMotorSpeed =  Yeetroller.Axis3.position() + Yeetroller.Axis1.position();
    // Get the velocity percentage of the right motor. (Axis3 - Axis1)
    int rightMotorSpeed = Yeetroller.Axis3.position() - Yeetroller.Axis1.position();

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
    

    //LIFT CODE

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


    //Forklift Code

    if (Yeetroller.ButtonL2.pressing() ) {
      forkliftLeft.spin(vex::directionType::rev, 75, vex::velocityUnits::pct);
      forkliftRight.spin(vex::directionType::rev, 75, vex::velocityUnits::pct);
    }
    else if (Yeetroller.ButtonL1.pressing()){
      forkliftLeft.spin(vex::directionType::fwd, 75, vex::velocityUnits::pct);
      forkliftRight.spin(vex::directionType::fwd, 75, vex::velocityUnits::pct);
    }
    else {
      forkliftLeft.stop(vex::brakeType::brake);
      forkliftRight.stop(vex::brakeType::brake);
    }

    

    
    

    //Testing Auton
    if (Yeetroller.ButtonUp.pressing()) {
      //move drivetrain forward and forklift down 
      // forkliftLeft.setVelocity(100, percent);
      // forkliftRight.setVelocity(100, percent);
      // rightDriveMotor.setVelocity(100, percent);
      // leftDriveMotor.setVelocity(100, percent);
      // leftDriveMotor.spin(vex::directionType::fwd);
      // rightDriveMotor.spin(vex::directionType::fwd);
      // forkliftLeft.spin(vex::directionType::rev);
      // forkliftRight.spin(vex::directionType::rev);
      // vex::task::sleep(1700);

      // rightDriveMotor.setVelocity(100, percent);
      // leftDriveMotor.setVelocity(100, percent);
      // leftDriveMotor.spin(vex::directionType::fwd);
      // rightDriveMotor.spin(vex::directionType::fwd);

      // vex::task::sleep(1000);

      // //move drivetrain forward a little bit 
      // forkliftLeft.setVelocity(100, percent);
      // forkliftRight.setVelocity(100, percent);
      // forkliftLeft.spin(vex::directionType::rev);
      // forkliftRight.spin(vex::directionType::rev);
      // vex::task::sleep(100);

      //move forklift up with goal 
      // forkliftLeft.setVelocity(100, percent);
      // forkliftRight.setVelocity(100, percent);
      // forkliftLeft.spin(vex::directionType::fwd);
      // forkliftRight.spin(vex::directionType::fwd);
      // rightDriveMotor.setVelocity(100, percent);
      // leftDriveMotor.setVelocity(100, percent);
      // leftDriveMotor.spin(vex::directionType::rev);
      // rightDriveMotor.spin(vex::directionType::fwd);
      // vex::task::sleep(1000);

      // //move drivetrain forward and forklift down 
      // forkliftLeft.setVelocity(100, percent);
      // forkliftRight.setVelocity(100, percent);
      // rightDriveMotor.setVelocity(100, percent);
      // leftDriveMotor.setVelocity(100, percent);
      // leftDriveMotor.spin(vex::directionType::fwd);
      // rightDriveMotor.spin(vex::directionType::fwd);
      // forkliftLeft.spin(vex::directionType::rev);
      // forkliftRight.spin(vex::directionType::rev);
      // vex::task::sleep(1200);

      // //move drivetrain forward a little bit 
      // forkliftLeft.setVelocity(100, percent);
      // forkliftRight.setVelocity(100, percent);
      // forkliftLeft.spin(vex::directionType::rev);
      // forkliftRight.spin(vex::directionType::rev);
      // vex::task::sleep(100);

      // //move forklift up with goal 
      // forkliftLeft.setVelocity(100, percent);
      // forkliftRight.setVelocity(100, percent);
      // forkliftLeft.spin(vex::directionType::fwd);
      // forkliftRight.spin(vex::directionType::fwd);
      // vex::task::sleep(1000);
      
      // //move backward with goal 
      // rightDriveMotor.setVelocity(100, percent);
      // leftDriveMotor.setVelocity(100, percent);
      // leftDriveMotor.spin(vex::directionType::rev);
      // rightDriveMotor.spin(vex::directionType::rev);
      // vex::task::sleep(1600);
      
    }
    else if(Yeetroller.ButtonDown.pressing()){
      //move forward
      rightDriveMotor.setVelocity(100, percent);
      leftDriveMotor.setVelocity(100, percent);
      leftDriveMotor.spin(vex::directionType::rev);
      rightDriveMotor.spin(vex::directionType::rev);
      vex::task::sleep(1700);
      //clamp down
      
      vex::task::sleep(100);
      //move backward with goal 
      
      rightDriveMotor.setVelocity(100, percent);
      leftDriveMotor.setVelocity(100, percent);
      leftDriveMotor.spin(vex::directionType::fwd);
      rightDriveMotor.spin(vex::directionType::fwd);
      vex::task::sleep(1800);
      leftDriveMotor.stop();
      rightDriveMotor.stop();
    }
    wait(20,msec);
    counter = 0;
  }
}