#include "main.h"

void BlueRightOneGoal() 
{
  FrontSpin.spinFor(forward,180,degrees,false);
  BackSpin.spinFor(forward,180,degrees,false);
  LeftClaw.spin(forward);
  RightClaw.spin(forward);

  float desiredValue;
  float desiredTurnValue;
  bool resetDriveSensors = true;
  bool enableDriverPID = true;

  BackSpin.spinFor(reverse,0.5*360,degrees,false);
  FrontSpin.spinFor(reverse,0.5*360,degrees,true);

  //BackSpin.spinFor(forward,1.6*360,degrees,false);
  //FrontSpin.spinFor(forward,1.6*360,degrees,true);

  ballreach();

  //////////////////////////////////////////////////////////

  float forward1 = 30.0;

  desiredValue = converter(forward1);
  desiredTurnValue = 0;
  drivePID(0.2,0,0.2, 0,0,0, desiredValue, desiredTurnValue, resetDriveSensors, enableDriverPID,25);

  /////////////////////////////////////////////////////////

  float turn1 = 130;

  desiredValue = 0;
  desiredTurnValue = turn1;
  drivePID(0,0,0, 0.25,0,0, desiredValue, desiredTurnValue, resetDriveSensors, enableDriverPID,10);

  //LeftClaw.spin(forward);
  //RightClaw.spin(forward);

  float forward2 = 7.0;

  desiredValue = converter(forward2);
  desiredTurnValue = 0;
  drivePID(0.25,0,0.15, 0,0,0, desiredValue, desiredTurnValue, resetDriveSensors, enableDriverPID,25);

  //hasRedCallBackCornerTower();

  //FrontSpin.spinFor(forward,2 * 360,degrees,false);
  //BackSpin.spinFor(forward,2 * 360, degrees,true);

  hasRedCallBackMiddleTower();

  float backward1 = -30.0;

  desiredValue = converter(backward1);
  desiredTurnValue = 0;
  drivePID(0.15,0,0.07, 0,0,0, desiredValue, desiredTurnValue, resetDriveSensors, enableDriverPID,-40);
}