#include "main.h"

void BlueNone() 
{
  FrontSpin.spinFor(forward,180,degrees,false);
  BackSpin.spinFor(forward,180,degrees,false);
  LeftClaw.spin(forward);
  RightClaw.spin(forward);
}