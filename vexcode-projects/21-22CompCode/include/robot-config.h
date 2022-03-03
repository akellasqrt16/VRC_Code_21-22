using namespace vex;

extern brain Brain;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void);

/*
* Initialization of motors and pnuematics
*/
extern vex::motor leftDriveMotor;
extern vex::motor rightDriveMotor;
extern vex::motor leftDriveMotor2;
extern vex::motor rightDriveMotor2;
extern vex::motor forkliftLeft;
extern vex::motor forkliftRight;
extern vex::motor leftLift;
extern vex::motor rightLift;
extern vex::controller Yeetroller;
extern digital_out p1;
extern digital_out p2;

/*
* Initialization of functions
*/
void moveForward(double deg);
void moveBackwards(double deg);
void turnLeft(double deg);
void turnRight(double deg);
void liftUp(double deg);
void liftDown(double deg);
void forkliftUp(double deg);
void forkliftDown(double deg);
void forkliftUp(double deg);
void printValueCont(int num, int pos);
void printTextCont(const char *str, int pos);
void leftSideAuton();
void rightSideAuton();
