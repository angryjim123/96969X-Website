#include "main.h"

void BlueTwo()
{
  if(Controller1.Axis3.position(percent) == 0)
  {
    startTimeA = Brain.timer(seconds);
  }
  
  if(Controller1.ButtonR1.pressing() && Controller1.ButtonL1.pressing() && Optical2.isNearObject())
  {
    //Let the task run instead of motordecision
  }
  else
  {
    motordecision();
  }

  //When the robot is next to a tower and ready to circulate balls. Completely Automatic.
  //Takes greatest priority other than wheel movements.
  if(Controller2.ButtonLeft.pressing())
  {
    checkRed.broadcastAndWait();
  }
  else
  {
    //Manually controlling the upperward / downward movement
    if (Controller2.ButtonR1.pressing())
    {
      FrontSpin.spin(forward);
      BackSpin.spin(forward);
    }
    else if (Controller2.ButtonR2.pressing())
    {
      FrontSpin.spin(reverse);
      BackSpin.spin(reverse);
    }
    else if(Controller2.ButtonY.pressing())
    {
      FrontSpin.spin(forward);
      BackSpin.spin(reverse);
    }
    else
    {
      FrontSpin.stop();
      BackSpin.stop();
    }
    //Manually controlling the inward / outward movement
    if (Controller2.ButtonL1.pressing())
    {
      RightClaw.spin(forward);
      LeftClaw.spin(forward);
    }
    else if (Controller2.ButtonL2.pressing())
    {
      RightClaw.spin(reverse);
      LeftClaw.spin(reverse);
    }
    else
    {
      RightClaw.stop();
      LeftClaw.stop();
    }
  }
}