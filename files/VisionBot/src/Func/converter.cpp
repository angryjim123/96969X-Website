#include "main.h"

float wheel_d = 4.3; //inches
float itc = 2.54; //1 inch = 2.54 cm
float circumference = wheel_d * itc * M_PI; //in cm

float converter(float number)
{
  return number / circumference * 360;
}