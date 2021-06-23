#include "main.h"

using namespace vex;

void ballreach()
{
  while(LineTrackerB.value( analogUnits::range12bit ) > 2943)
  {
    BackSpin.spin(forward);
    FrontSpin.spin(forward);
  }
  BackSpin.stop();
  FrontSpin.stop();
}