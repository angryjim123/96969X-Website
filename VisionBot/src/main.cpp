/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\User                                             */
/*    Created:      Wed Dec 16 2020                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// RightFrontWheel      motor         15              
// RightBackWheel       motor         7               
// LeftFrontWheel       motor         20              
// LeftBackWheel        motor         10              
// FrontSpin            motor         6               
// BackSpin             motor         12              
// LeftClaw             motor         17              
// RightClaw            motor         16              
// Vision5              vision        1               
// LineTrackerB         line          B               
// Controller2          controller                    
// Optical2             optical       2               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "main.h"

using namespace vex;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// A global instance of competition
competition Competition;

double startTimeA = Brain.timer(seconds);
double startTimeSpin = Brain.timer(seconds);
int decision[3];
event checkBlue = event();
event checkRed = event();
void (*Autonfunction)();
void (*Driverfunction)();
motor_group allDrive (LeftFrontWheel, LeftBackWheel, RightFrontWheel, RightBackWheel);

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  Selection();

  //Auton Selection
  if(decision[1] == 1)
  {
    if(decision[2] == 1)
    {
      Autonfunction = &BlueLeftOneGoal;
    }
    else if(decision[2] == 2)
    {
      Autonfunction = &BlueLeftTwoGoal;
    }
    else if(decision[2] == 3)
    {
      Autonfunction = &BlueRightOneGoal;
    }
    else if(decision[2] == 4)
    {
      Autonfunction = &BlueRightTwoGoal;
    }
    else 
    {
      Autonfunction = &BlueNone;
    }
  }
  else
  {
    if(decision[2] == 1)
    {
      Autonfunction = &RedLeftOneGoal;
    }
    else if(decision[2] == 2)
    {
      Autonfunction = &RedLeftTwoGoal;
    }
    else if(decision[2] == 3)
    {
      Autonfunction = &RedRightOneGoal;
    }
    else if(decision[2] == 4)
    {
      Autonfunction = &RedRightTwoGoal;
    }
    else 
    {
      Autonfunction = &RedNone;
    }
  }

  //Driver Selection

  if(decision[0] == 1)
  {
    if(decision[1] == 1)
    {
      Driverfunction = &BlueJ;
      checkRed(hasRedCallbackDriverControl);
    }
    else
    {
      Driverfunction = &RedJ;
      checkBlue(hasBlueCallbackDriverControl);
    }
  }
  else
  {
    if(decision[1] == 1)
    {
      Driverfunction = &BlueTwo;
      checkRed(hasRedCallbackDriverControl);
    }
    else
    {
      Driverfunction = &RedTwo;
      checkBlue(hasBlueCallbackDriverControl);
    }
  }
  
  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
  return;
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/


void autonomous(void) {
  AutonInitial();

  //RedLeftTwoGoal();
  (*Autonfunction)();
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {

  

  // User control code here, inside the loop
  UserInitial();

  Optical2.setLight(ledState::on);

  task myTask = task(myTaskCallBack);
  
  while(true)
  {
    //RedJ();
    //checkBlue(hasBlueCallbackDriverControl);
    (*Driverfunction)();
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {

  pre_auton();
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
