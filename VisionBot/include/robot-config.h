using namespace vex;

extern brain Brain;

using signature = vision::signature;

// VEXcode devices
extern controller Controller1;
extern motor RightFrontWheel;
extern motor RightBackWheel;
extern motor LeftFrontWheel;
extern motor LeftBackWheel;
extern motor FrontSpin;
extern motor BackSpin;
extern motor LeftClaw;
extern motor RightClaw;
extern signature Vision5__REDBOX;
extern signature Vision5__BLUEBOX;
extern signature Vision5__SIG_3;
extern signature Vision5__SIG_4;
extern signature Vision5__SIG_5;
extern signature Vision5__SIG_6;
extern signature Vision5__SIG_7;
extern vision Vision5;
extern line LineTrackerB;
extern controller Controller2;
extern optical Optical2;
extern double startTimeA;
extern double startTimeSpin;
extern int decision[3];
extern event checkBlue;
extern event checkRed;
extern motor_group allDrive;
/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );