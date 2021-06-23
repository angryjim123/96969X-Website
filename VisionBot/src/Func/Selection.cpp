#include "main.h"

void Selection()
{
  bool confirm = false;
  
  while(!confirm)
  {

    Brain.Screen.clearScreen();
    Brain.Screen.setFont(mono20);
    Brain.Screen.setPenColor(white);

    std::string decisionwords [3];
    
    int MaxX = 480,MaxY = 240;
    int offsetX = 90;
    int fontSizeY = 20;
    int OneX = 0, OneY = 0, TwoX = 240, TwoY = 0;

    Brain.Screen.drawRectangle(OneX, OneY, MaxX/2, MaxY, purple);
    Brain.Screen.drawRectangle(TwoX, TwoY, MaxX/2, MaxY, green);
    Brain.Screen.setFillColor(purple);
    Brain.Screen.printAt((OneX * 2 + MaxX / 2 - offsetX) / 2, (OneY * 2 + MaxY - fontSizeY) / 2,"One Driver");
    Brain.Screen.setFillColor(green);
    Brain.Screen.printAt((TwoX * 2 + MaxX / 2 - offsetX) / 2, (TwoY * 2 + MaxY - fontSizeY) / 2,"Two Driver");

    bool pressed = false;

    wait(1000, msec);

    while(!pressed)
    {
      if(Brain.Screen.pressing())
      {
        int Xpos = Brain.Screen.xPosition();
        int Ypos = Brain.Screen.yPosition();

        if(Xpos >= OneX && Xpos <= OneX + MaxX / 2 && Ypos >= OneY && Ypos <= OneY + MaxY)
        {
          pressed = true;
          decision[0] = 1;
          decisionwords[0] = "One Driver";
        }
        else if(Xpos >= TwoX && Xpos <= TwoX + MaxX / 2 && Ypos >= TwoY && Ypos <= TwoY + MaxY)
        {
          pressed = true;
          decision[0] = 2;
          decisionwords[0] = "Two Driver";
        }
      }
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////

    pressed = false;

    offsetX = 70;

    Brain.Screen.drawRectangle(OneX, OneY, MaxX/2, MaxY, blue);
    Brain.Screen.drawRectangle(TwoX, TwoY, MaxX/2, MaxY, red);
    Brain.Screen.setFillColor(blue);
    Brain.Screen.printAt((OneX * 2 + MaxX / 2 - offsetX) / 2, (OneY * 2 + MaxY - fontSizeY) / 2,"Blue");
    Brain.Screen.setFillColor(red);
    Brain.Screen.printAt((TwoX * 2 + MaxX / 2 - offsetX) / 2, (TwoY * 2 + MaxY - fontSizeY) / 2,"Red");

    wait(1000, msec);

    while(!pressed)
    {
      if(Brain.Screen.pressing())
      {
        int Xpos = Brain.Screen.xPosition();
        int Ypos = Brain.Screen.yPosition();

        if(Xpos >= OneX && Xpos <= OneX + MaxX / 2 && Ypos >= OneY && Ypos <= OneY + MaxY)
        {
          pressed = true;
          decision[1] = 1;
          decisionwords[1] = "Blue";
        }
        else if(Xpos >= TwoX && Xpos <= TwoX + MaxX / 2 && Ypos >= TwoY && Ypos <= TwoY + MaxY)
        {
          pressed = true;
          decision[1] = 2;
          decisionwords[1] = "Red";
        }
      }
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////

    pressed = false;

    int L1X = 0, L1Y = 0, L2X = 0, L2Y = 120;
    int R1X = 320, R1Y = 0, R2X = 320, R2Y = 120;
    int NAX = 160, NAY = 0;

    Brain.Screen.drawRectangle(L1X, L1Y, MaxX/3, MaxY/2, yellow);
    Brain.Screen.drawRectangle(L2X, L2Y, MaxX/3, MaxY/2, orange);
    Brain.Screen.drawRectangle(R1X, R1Y, MaxX/3, MaxY/2, green);
    Brain.Screen.drawRectangle(R2X, R2Y, MaxX/3, MaxY/2, purple);
    Brain.Screen.drawRectangle(NAX, NAY, MaxX/3, MaxY, black);
    Brain.Screen.setFillColor(yellow);
    Brain.Screen.printAt((L1X * 2 + MaxX / 3 - offsetX) / 2, (L1Y * 2 + MaxY / 2 - fontSizeY) / 2,"L1");
    Brain.Screen.setFillColor(orange);
    Brain.Screen.printAt((L2X * 2 + MaxX / 3 - offsetX) / 2, (L2Y * 2 + MaxY / 2 - fontSizeY) / 2,"L2");
    Brain.Screen.setFillColor(green);
    Brain.Screen.printAt((R1X * 2 + MaxX / 3 - offsetX) / 2, (R1Y * 2 + MaxY / 2 - fontSizeY) / 2,"R1");
    Brain.Screen.setFillColor(purple);
    Brain.Screen.printAt((R2X * 2 + MaxX / 3 - offsetX) / 2, (R2Y * 2 + MaxY / 2 - fontSizeY) / 2,"R2");
    Brain.Screen.setFillColor(black);
    Brain.Screen.printAt((NAX * 2 + MaxX / 3 - offsetX) / 2, (NAY * 2 + MaxY - fontSizeY) / 2,"None");

    wait(1000, msec);

    while(!pressed)
    {
      if(Brain.Screen.pressing())
      {
        int Xpos = Brain.Screen.xPosition();
        int Ypos = Brain.Screen.yPosition();

        if(Xpos >= L1X && Xpos <= L1X + MaxX / 3 && Ypos >= L1Y && Ypos <= L1Y + MaxY / 2)
        {
          pressed = true;
          decision[2] = 1;
          decisionwords[2] = "Left 1 Goal";
        }
        else if(Xpos >= L2X && Xpos <= L2X + MaxX / 3 && Ypos >= L2Y && Ypos <= L2Y + MaxY / 2)
        {
          pressed = true;
          decision[2] = 2;
          decisionwords[2] = "Left 2 Goals";
        }
        else if(Xpos >= R1X && Xpos <= R1X + MaxX / 3 && Ypos >= R1Y && Ypos <= R1Y + MaxY / 2)
        {
          pressed = true;
          decision[2] = 3;
          decisionwords[2] = "Right 1 Goal";
        }
        else if(Xpos >= R2X && Xpos <= R2X + MaxX / 3 && Ypos >= R2Y && Ypos <= R2Y + MaxY / 2)
        {
          pressed = true;
          decision[2] = 4;
          decisionwords[2] = "Right 2 Goals";
        }
        else if(Xpos >= NAX && Xpos <= NAX + MaxX / 3 && Ypos >= NAY && Ypos <= NAY + MaxY)
        {
          pressed = true;
          decision[2] = 5;
          decisionwords[2] = "No Goal";
        }
      }
    }
    Brain.Screen.clearScreen();
    Brain.Screen.setCursor(1,1);
    Brain.Screen.print(decisionwords[0].c_str());
    Brain.Screen.newLine();
    Brain.Screen.print(decisionwords[1].c_str());
    Brain.Screen.newLine();
    Brain.Screen.print(decisionwords[2].c_str());
    Brain.Screen.newLine();

    pressed = false;

    int OKX = 0, OKY = 180, NOX = 240, NOY = 180;
    Brain.Screen.drawRectangle(OKX, OKY, MaxX/2, 60, blue);
    Brain.Screen.drawRectangle(NOX, NOY, MaxX/2, 60, red);
    Brain.Screen.setFillColor(blue);
    Brain.Screen.printAt((OKX * 2 + MaxX / 2 - offsetX) / 2, (OKY * 2 + 60 - fontSizeY) / 2,"Confirm");
    Brain.Screen.setFillColor(red);
    Brain.Screen.printAt((NOX * 2 + MaxX / 2 - offsetX) / 2, (NOY * 2 + 60 - fontSizeY) / 2,"Restart");

    wait(1000, msec);

    while(!pressed)
    {
      if(Brain.Screen.pressing())
      {
        int Xpos = Brain.Screen.xPosition();
        int Ypos = Brain.Screen.yPosition();

        if(Xpos >= OKX && Xpos <= OKX + MaxX / 2 && Ypos >= OKY && Ypos <= OKY + 60)
        {
          pressed = true;
          confirm = true;
        }
        else if(Xpos >= NOX && Xpos <= NOX + MaxX / 2 && Ypos >= NOY && Ypos <= NOY + 60)
        {
          pressed = true;
        }
      }
    }
  }
  Brain.Screen.clearScreen();
  return;
}

