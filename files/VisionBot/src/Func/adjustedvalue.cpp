#include "main.h"

/**
 * Allows the motor to go in a 1/log scale.
 */
float motorvalue(float t)
{
  return 1 / (log10(100.0 - 90.0 * t / threshold ));
}

float turnvalue(float t)
{
  return 1 / (log10(100.0 - 90.0 * t / threshold ));
}