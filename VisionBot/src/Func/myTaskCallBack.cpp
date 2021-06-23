#include "main.h"

int myTaskCallBack()
{
  int counting = 0;
  while(true)
  {
    if(Optical2.isNearObject() && Controller1.ButtonR1.pressing() && Controller1.ButtonL1.pressing())
    {
      counting++;
      if(counting <= 10)
      {
        allDrive.spin(forward);
      }
      else if(counting <= 59)
      {
        allDrive.stop();
      }
      else if(counting <= 60)
      {
        counting = 0;
      }
    }
    task::sleep(20);
  }
  
  return 0;
}