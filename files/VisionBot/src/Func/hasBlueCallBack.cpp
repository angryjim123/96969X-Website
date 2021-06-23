#include "main.h"

/**
 * Cotinues to circulate the balls until a red one is spotted and exited from the back FOR DRIVER
 */
void hasBlueCallbackDriverControl() {
  RightClaw.spin(forward);
  LeftClaw.spin(forward);
  Vision5.takeSnapshot(Vision5__BLUEBOX);
  if (Vision5.objectCount > 0) {
    int max = 0;
    //Loop through all "Red" objects and spotting the one that has the largest width.
    //If largest width is geater 150, then a red ball is spotted. It will then escape the while loop.
    for(int x = 0 ; x < Vision5.objectCount ; x++)
    {
      if(Vision5.objects[x].width > max)
      {
        max = Vision5.objects[x].width;
      }
    }
    if(max >= 150)
    {
      //If a red ball is spotted, it is exited through the back.
      FrontSpin.spin(forward);
      BackSpin.spin(reverse);
    }
    else
    {
      //If no red ball is spotted, circulation mechanism continues.
      FrontSpin.spin(forward);
      BackSpin.spin(forward);
    }
  }
  else
  {
    //This part is when there are no red objects within the view. For instance, when blue ball blocks the vision sensor. Thus, it continues to circulate.
    FrontSpin.spin(forward);
    BackSpin.spin(forward);
  }
}


/**
 * Cotinues to circulate the balls until a red one is spotted FOR AUTONOMOUS
 */
void hasBlueCallBackCornerTower(){
  bool out = true;
  RightClaw.spin(forward);
  LeftClaw.spin(forward);
  FrontSpin.spin(forward);
  BackSpin.spin(forward);
  while(out)
  {
    Vision5.takeSnapshot(Vision5__BLUEBOX);
    if (Vision5.objectCount > 0)
    {
      int max = 0;
      //Loop through all "Red" objects and spotting the one that has the largest width.
      //If largest width is geater 150, then a red ball is spotted. It will then escape the while loop.
      for(int x = 0 ; x < Vision5.objectCount ; x++)
      {
        if(Vision5.objects[x].width > max)
        {
          max = Vision5.objects[x].width;
        }
      }
      if(max >= 150)
      {
      out = false;
      }
    }
    task::sleep(20);
  }

  //Circulation mechanism continues to shoot balls up because there might still be a blue ball above the spotted red ball.
  //In the case where there are no blue balls above, the circulation mechanism still will not shoot out the red ball.
  //Claws spin in reverse to make sure blue ball does not come out while the robot exits the tower.
  FrontSpin.rotateFor(0.5,rotationUnits::rev,false);
  BackSpin.rotateFor(0.5,rotationUnits::rev,false);
  LeftClaw.rotateFor(-0.8,rotationUnits::rev,false);
  RightClaw.rotateFor(-0.8,rotationUnits::rev,true);

  return;
}


/**
 * Cotinues to circulate the balls until a red one is spotted FOR AUTONOMOUS
 */
void hasBlueCallBackMiddleTower(){
  bool out = true;
  RightClaw.spin(forward);
  LeftClaw.spin(forward);
  FrontSpin.spin(forward);
  BackSpin.spin(forward);
  int count = 0;
  while(out)
  {
    if(count <= 10)
    {
      allDrive.spin(forward);
    }

    else if(count <= 59)
    {
      allDrive.stop();
    }
    /*
    else if(count <= 40)
    {
      allDrive.spin(reverse);
    }
    */
    else if(count <= 60)
    {
      count = 0;
      allDrive.stop();
    }

    Vision5.takeSnapshot(Vision5__BLUEBOX);
    if (Vision5.objectCount > 0)
    {
      int max = 0;
      //Loop through all "Red" objects and spotting the one that has the largest width.
      //If largest width is geater 150, then a red ball is spotted. It will then escape the while loop.
      for(int x = 0 ; x < Vision5.objectCount ; x++)
      {
        if(Vision5.objects[x].width > max)
        {
          max = Vision5.objects[x].width;
        }
      }
      if(max >= 150)
      {
      out = false;
      }
    }
    count++;
    task::sleep(20);
  }

  //Circulation mechanism continues to shoot balls up because there might still be a blue ball above the spotted red ball.
  //In the case where there are no blue balls above, the circulation mechanism still will not shoot out the red ball.
  //Claws spin in reverse to make sure blue ball does not come out while the robot exits the tower.
  FrontSpin.rotateFor(0.5,rotationUnits::rev,false);
  BackSpin.rotateFor(0.5,rotationUnits::rev,false);
  LeftClaw.rotateFor(-0.8,rotationUnits::rev,false);
  RightClaw.rotateFor(-0.8,rotationUnits::rev,true);

  return;
}