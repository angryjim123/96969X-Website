#include "main.h"

void motordecision()
{
  int rightwheelinputs;
  int leftwheelinputs;
  float factor;
  float constantvalue = 1.1;
  double currentTimeSpin;
  int previous = -1;
  double spinfactor;
  //double spinfactor = 1;


  double currentTime = Brain.timer(seconds) - startTimeA;
  if(currentTime < threshold && (Controller1.Axis3.position(percent) >= 60 || Controller1.Axis3.position(percent) <= -60))
  {
    float inputime = currentTime;
    factor = motorvalue(inputime);
  }
  else
  {
    factor = 1;
  }

  if(Controller1.Axis1.position(percent) > 0)
  {

    if(previous != 1)
    {
      startTimeSpin = Brain.timer(seconds);
      previous =1;
    }
    currentTimeSpin = Brain.timer(seconds) - startTimeSpin;
    spinfactor = turnvalue(currentTimeSpin);


    if(Controller1.Axis3.position(percent) != 0)
    {
      rightwheelinputs = Controller1.Axis3.position(percent) - spinfactor * constantvalue * std::min(Controller1.Axis1.position(percent),Controller1.Axis3.position(percent));
      leftwheelinputs = Controller1.Axis3.position(percent);
    }
    else
    {
      leftwheelinputs = Controller1.Axis1.position(percent);
      rightwheelinputs = -Controller1.Axis1.position(percent);
    }


  }
  else if(Controller1.Axis1.position(percent) < 0)
  {

    if(previous != 2)
    {
      startTimeSpin = Brain.timer(seconds);
      previous = 2;
    }
    currentTimeSpin = Brain.timer(seconds) - startTimeSpin;
    spinfactor = turnvalue(currentTimeSpin);

    if(Controller1.Axis3.position(percent) != 0)
    {
      rightwheelinputs = Controller1.Axis3.position(percent);
      leftwheelinputs = Controller1.Axis3.position(percent) - spinfactor * constantvalue * std::max(Controller1.Axis1.position(percent),Controller1.Axis3.position(percent));
    }
    else
    {
      leftwheelinputs = Controller1.Axis1.position(percent);
      rightwheelinputs = -Controller1.Axis1.position(percent);
    }


  }
  else
  {
    rightwheelinputs = Controller1.Axis3.position(percent);
    leftwheelinputs = Controller1.Axis3.position(percent);
  }

  float rightinput = rightwheelinputs * factor;
  float leftinput = leftwheelinputs * factor;

  RightBackWheel.spin(directionType::fwd, rightinput, velocityUnits::pct);
  RightFrontWheel.spin(directionType::fwd, rightinput, velocityUnits::pct);
  LeftBackWheel.spin(directionType::fwd, leftinput, velocityUnits::pct);
  LeftFrontWheel.spin(directionType::fwd, leftinput, velocityUnits::pct);
}