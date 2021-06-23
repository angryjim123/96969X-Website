#pragma once
#include "main.h"

int drivePID(float kP, float kI, float kD, float turnkP, float turnkI, float turnkD, float desiredValue, float desiredTurnValue, bool resetDriveSensors, bool enableDriverPID, int basepower);