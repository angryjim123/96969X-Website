#include "main.h"

int pctdivider = 1;

int maxTurnIntegral = 300; // These cap the integrals
int maxIntegral = 300;
int integralBound = 3; //If error is outside the bounds, then apply the integral. This is a buffer with +-integralBound degrees

int error = 0; //SensorValue - Desired Value : Positional
int prevError = 0; //Position 20 ms ago
int derivative = 0; //Error - prevError : Speed
int totalError = 0; //totalError = totalError + error

int turnError = 0; //SensorValue - Desired Value : Positional
int turnPrevError = 0; //Position 20 ms ago
int turnDerivative = 0; //Error - prevError : Speed
int turnTotalError = 0; //totalError = totalError + error

int basepower = 20;

//Pasted from a C++ resource
double signnum_c(double x) {
  if (x > 0.0) return 1.0;
  if (x < 0.0) return -1.0;
  return x;
}

int drivePID(float kP, float kI, float kD, float turnkP, float turnkI, float turnkD, float desiredValue, float desiredTurnValue, bool resetDriveSensors, bool enableDriverPID, int basepower)
{
  while(enableDriverPID)
  {
    if(resetDriveSensors)
    {
      resetDriveSensors = false;
      RightFrontWheel.setPosition(0,degrees);
      LeftFrontWheel.setPosition(0,degrees);
      RightBackWheel.setPosition(0,degrees);
      LeftBackWheel.setPosition(0,degrees);
    }

    //Positions of motors
    int leftFrontMotorPosition = LeftFrontWheel.position(degrees);
    int rightFrontMotorPosition = RightFrontWheel.position(degrees);
    int leftBackMotorPosition = LeftBackWheel.position(degrees);
    int rightBackMotorPosition = RightBackWheel.position(degrees);

    //////////////////////////////////////////////////////////////////////////////////////////
    //Lateral Movement PID
    //////////////////////////////////////////////////////////////////////////////////////////
    //Average positions of all four motors.
    int averagePosition = (leftFrontMotorPosition + rightFrontMotorPosition + leftBackMotorPosition + rightBackMotorPosition) / 4;

    //Potential
    error = desiredValue - averagePosition;

    //Derivative
    derivative = error - prevError;

    //Integral
    //
    //totalError += error;
    if(abs(error) < integralBound){
    totalError+=error;
    }  else {
    totalError = 0;
    }

    totalError = abs(totalError) > maxIntegral ? signnum_c(totalError) * maxIntegral : totalError;

    double lateralMotorPower = (error * kP + derivative * kD + totalError * kI) / pctdivider;

    //////////////////////////////////////////////////////////////////////////////////////////
    //Turning Movement PID
    //////////////////////////////////////////////////////////////////////////////////////////
    //Average positions of all four motors.
    int turnDifference = (( leftFrontMotorPosition + leftBackMotorPosition ) - (rightFrontMotorPosition + rightBackMotorPosition))/4;

    //Potential
    turnError = desiredTurnValue - turnDifference;

    //Derivative
    turnDerivative = turnError - turnPrevError;

    //Integral
    //
    //turnTotalError += turnError;
    if(abs(error) < integralBound){
    turnTotalError+=turnError;
    }  else {
    turnTotalError = 0;
    }

    turnTotalError = abs(turnTotalError) > maxIntegral ? signnum_c(turnTotalError) * maxIntegral : turnTotalError;

    double turnMotorPower = (turnError * turnkP + turnDerivative * turnkD + turnTotalError * turnkI) / pctdivider;

    int dirr;
    int dirl;

    if(lateralMotorPower - turnMotorPower >= 0)
    {
      dirr = 1;
    }
    else
    {
      dirr = -1;
    }

    if(lateralMotorPower + turnMotorPower >= 0)
    {
      dirl = 1;
    }
    else
    {
      dirl = -1;
    }

    LeftFrontWheel.spin(forward, dirl * std::max(std::abs(basepower),std::abs(lateralMotorPower + turnMotorPower)), pct);
    RightFrontWheel.spin(forward, dirr * std::max(std::abs(basepower),std::abs(lateralMotorPower - turnMotorPower)), pct);
    LeftBackWheel.spin(forward, dirl * std::max(std::abs(basepower),std::abs(lateralMotorPower + turnMotorPower)), pct);
    RightBackWheel.spin(forward, dirr * std::max(std::abs(basepower),std::abs(lateralMotorPower - turnMotorPower)), pct);

    prevError = error;
    turnPrevError = turnError;
    if(std::abs(desiredValue) > 1 && std::abs(desiredValue - averagePosition) < 5)
    {
      enableDriverPID = false;
    }
    else if(std::abs(desiredTurnValue) > 1 && std::abs(turnDifference - desiredTurnValue) < 5)
    {
      enableDriverPID = false;
    }

    task::sleep(20);
  }

  LeftFrontWheel.stop();
  RightFrontWheel.stop();
  LeftBackWheel.stop();
  RightBackWheel.stop();
  return 1;
}