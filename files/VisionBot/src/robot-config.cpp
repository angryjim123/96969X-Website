#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
motor RightFrontWheel = motor(PORT15, ratio18_1, true);
motor RightBackWheel = motor(PORT7, ratio18_1, true);
motor LeftFrontWheel = motor(PORT20, ratio18_1, false);
motor LeftBackWheel = motor(PORT10, ratio18_1, false);
motor FrontSpin = motor(PORT6, ratio6_1, false);
motor BackSpin = motor(PORT12, ratio6_1, false);
motor LeftClaw = motor(PORT17, ratio18_1, false);
motor RightClaw = motor(PORT16, ratio18_1, true);
/*vex-vision-config:begin*/
signature Vision5__REDBOX = signature (1, 5795, 7037, 6416, -247, 2535, 1144, 4.8, 0);
signature Vision5__BLUEBOX = signature (2, -4743, -3359, -4050, 10369, 13255, 11812, 5.5, 0);
vision Vision5 = vision (PORT1, 45, Vision5__REDBOX, Vision5__BLUEBOX);
/*vex-vision-config:end*/
line LineTrackerB = line(Brain.ThreeWirePort.B);
controller Controller2 = controller(partner);
optical Optical2 = optical(PORT2);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}