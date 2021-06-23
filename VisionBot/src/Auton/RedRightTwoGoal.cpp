#include "main.h"

void RedRightTwoGoal() 
{
  FrontSpin.spinFor(forward,180,degrees,false);
  BackSpin.spinFor(forward,180,degrees,false);
  LeftClaw.spin(forward);
  RightClaw.spin(forward);

  float desiredValue;
  float desiredTurnValue;
  bool resetDriveSensors = true;
  bool enableDriverPID = true;
  int base = 20;

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

  hasBlueCallBackMiddleTower();

  float backward1 = -140.0;

  desiredValue = converter(backward1);
  desiredTurnValue = 0;
  drivePID(0.15,0,0.07, 0,0,0, desiredValue, desiredTurnValue, resetDriveSensors, enableDriverPID,-40);

  FrontSpin.spinFor(forward,2.9 * 360,degrees,false);
  BackSpin.spinFor(forward,2.9 * 360, degrees,true);

  LeftClaw.stop();
  RightClaw.stop();

  float turn2 = 255;

  desiredValue = 0;
  desiredTurnValue = turn2;
  drivePID(0,0,0, 0.2,0,0.15, desiredValue, desiredTurnValue, resetDriveSensors, enableDriverPID,8);

  LeftClaw.spin(forward);
  RightClaw.spin(forward);

  float forward3 = 83;

  desiredValue = converter(forward3);
  desiredTurnValue = 0;
  drivePID(0.22,0,0.1, 0,0,0, desiredValue, desiredTurnValue, resetDriveSensors, enableDriverPID,base);

  hasBlueCallBackMiddleTower();

  LeftClaw.spin(reverse);
  RightClaw.spin(reverse);

  float backward2 = -50.0;

  desiredValue = converter(backward2);
  desiredTurnValue = 0;
  drivePID(0.08,0,0, 0,0,0, desiredValue, desiredTurnValue, resetDriveSensors, enableDriverPID,-40);

  task::sleep(2000);

  LeftClaw.stop();
  RightClaw.stop();

}