// AUTON CODE POG
/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       pranavakella                                              */
/*    Created:      Mon Aug 10 2020                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// ---- END VEXCODE CONFIGURED DEVICES ----


//Before running this code, make sure the ports for the motors are identical to the ports mentioned in the code
//To move the left motor, move the left stick, while to move the right motor, move the right stick










#include "vex.h"

using namespace vex;
// idk why i'm including this stuff but the tutorial I watched had this
vex::brain    Brain;
vex::competition    Competition;

//Setting up the motors we are going to use

//Make sure to CHANGE THE PORT NUMBER TO THE PORT THAT THE CORRESPONDING MOTOR IS PLUGGED INTO

//Drivetrain
vex::motor  leftTopDriveMotor = vex::motor( vex:: PORT1);
vex::motor  rightTopDriveMotor = vex::motor( vex:: PORT2);
vex::motor  leftBottomDriveMotor = vex::motor( vex:: PORT3);
vex::motor  rightBottomDriveMotor = vex::motor( vex:: PORT4);



//VCB
vex::motor  vcb = vex::motor( vex:: PORT5, true);

//Shell
vex::motor shell = vex::motor( vex:: PORT6, true);

//Intakes
vex::motor  LeftIntake = vex::motor( vex:: PORT9); //Change port
vex::motor  RightIntake = vex::motor( vex:: PORT10, true); //Change port


//Setting up the controller
//The memes continue

vex::controller Yeetroller = vex::controller();


//CONSTANTS
int driveSpeed = 100;



//Stuff like calibrating sensors, positioning lift, etc.
void setup (void) {


}

void moveForward(int timeInput){
  leftTopDriveMotor.spin(vex::directionType::fwd, driveSpeed, vex::velocityUnits::pct);
  rightBottomDriveMotor.spin(vex::directionType::rev, driveSpeed, vex::velocityUnits::pct);
  leftBottomDriveMotor.spin(vex::directionType::rev, driveSpeed, vex::velocityUnits::pct);
  rightTopDriveMotor.spin(vex::directionType::fwd, driveSpeed, vex::velocityUnits::pct);
  wait
}






//The code for the autonomous period (when we get around to doing that)
void auton (void) {


}


int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
}
