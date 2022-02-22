#include "vex.h"
#include "robot-config.h"

using namespace vex;

// A global instance of brain used for printing to the V5 brain screen
brain Brain;

/*
* Definition of motors, pnuematics, and controller
*/
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
vex::motor  leftLift = vex::motor( vex:: PORT19);
vex::motor  rightLift = vex::motor( vex:: PORT14,true);

//Pnuematics
digital_out p1 = digital_out(Brain.ThreeWirePort.A);
digital_out p2 = digital_out(Brain.ThreeWirePort.B);

//Controller setup
vex::controller Yeetroller = vex::controller();



/*
* Definition of motors, pnuematics, and controller
*/


/*
* Move straight
*
* Input of 360 = 1/2 of tile
*/
void moveForward(double deg){
  rightDriveMotor.setVelocity(100, percent);
  leftDriveMotor.setVelocity(100, percent);
  rightDriveMotor2.setVelocity(100, percent);
  leftDriveMotor2.setVelocity(100, percent);
  leftDriveMotor.startRotateFor(vex::directionType::fwd, deg, vex::rotationUnits::deg);
  rightDriveMotor.rotateFor(vex::directionType::fwd, deg, vex::rotationUnits::deg);
  leftDriveMotor2.startRotateFor(vex::directionType::fwd, deg, vex::rotationUnits::deg);
  rightDriveMotor2.rotateFor(vex::directionType::fwd, deg, vex::rotationUnits::deg);
}

void moveBackwards(double deg){
  rightDriveMotor.setVelocity(100, percent);
  leftDriveMotor.setVelocity(100, percent);
  rightDriveMotor2.setVelocity(100, percent);
  leftDriveMotor2.setVelocity(100, percent);
  leftDriveMotor.startRotateFor(vex::directionType::rev, deg, vex::rotationUnits::deg);
  rightDriveMotor.startRotateFor(vex::directionType::rev, deg, vex::rotationUnits::deg);
  leftDriveMotor2.startRotateFor(vex::directionType::rev, deg, vex::rotationUnits::deg);
  rightDriveMotor2.rotateFor(vex::directionType::rev, deg, vex::rotationUnits::deg);
}


/*
* Turn
*
* Input of ? = 90 degree turn
*/
void turnLeft(double deg){
  rightDriveMotor.setVelocity(100, percent);
  leftDriveMotor.setVelocity(100, percent);
  rightDriveMotor2.setVelocity(100, percent);
  leftDriveMotor2.setVelocity(100, percent);
  leftDriveMotor.startRotateFor(vex::directionType::rev, deg, vex::rotationUnits::deg);
  rightDriveMotor.startRotateFor(vex::directionType::fwd, deg, vex::rotationUnits::deg);
  leftDriveMotor2.startRotateFor(vex::directionType::rev, deg, vex::rotationUnits::deg);
  rightDriveMotor2.rotateFor(vex::directionType::fwd, deg, vex::rotationUnits::deg);
}

void turnRight(double deg){
  rightDriveMotor.setVelocity(100, percent);
  leftDriveMotor.setVelocity(100, percent);
  rightDriveMotor2.setVelocity(100, percent);
  leftDriveMotor2.setVelocity(100, percent);
  leftDriveMotor.startRotateFor(vex::directionType::fwd, deg, vex::rotationUnits::deg);
  rightDriveMotor.startRotateFor(vex::directionType::rev, deg, vex::rotationUnits::deg);
  leftDriveMotor2.startRotateFor(vex::directionType::fwd, deg, vex::rotationUnits::deg);
  rightDriveMotor2.rotateFor(vex::directionType::rev, deg, vex::rotationUnits::deg);
}


/*
* Move lift
*
* Input of ? = fully up/down
*/
void liftUp(double deg){
 rightLift.setVelocity(100, percent);
 leftLift.setVelocity(100, percent);
 leftLift.startRotateFor(vex::directionType::fwd, deg, vex::rotationUnits::deg);
 rightLift.rotateFor(vex::directionType::fwd, deg, vex::rotationUnits::deg);
}

void liftDown(double deg){
 rightLift.setVelocity(100, percent);
 leftLift.setVelocity(100, percent);
 leftLift.startRotateFor(vex::directionType::rev, deg, vex::rotationUnits::deg);
 rightLift.rotateFor(vex::directionType::rev, deg, vex::rotationUnits::deg);
}


/*
* Move forklift
*
* Input of ? = fully up/down
*/
void forkliftUp(double deg){
  forkliftRight.setVelocity(100, percent);
  forkliftLeft.setVelocity(100, percent);
  forkliftLeft.startRotateFor(vex::directionType::fwd, deg, vex::rotationUnits::deg);
  forkliftRight.rotateFor(vex::directionType::fwd, deg, vex::rotationUnits::deg);
}
void forkliftDown(double deg){
  forkliftRight.setVelocity(100, percent);
  forkliftLeft.setVelocity(100, percent);
  forkliftLeft.startRotateFor(vex::directionType::rev, deg, vex::rotationUnits::deg);
  forkliftRight.rotateFor(vex::directionType::rev, deg, vex::rotationUnits::deg);
}


/*
* Left side auton
*
* Alignment: ___
*/
void leftSideAuton(){

}


/*
* Right side auton
*
* Alignment: ___
*/
void rightSideAuton(){
  //lol
}



















//Mostly useless functions

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void) {
}
void printValueCont(int num, int pos) {
  Yeetroller.Screen.clearScreen();
  Yeetroller.Screen.setCursor(pos,1);
  Yeetroller.Screen.print(num);
}

void printTextCont(const char *str, int pos){
  Yeetroller.Screen.clearScreen();
  Yeetroller.Screen.setCursor(pos, 1);
  Yeetroller.Screen.print(str);
}