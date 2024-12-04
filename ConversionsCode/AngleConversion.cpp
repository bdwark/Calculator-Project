#include <string>
#include <iostream>
#include <cmath>
#include "AngleConversion.h"

/*
    Angle Conversions
    Returns floats
*/

float pi = 2 * acos(0);

//Takes angle in degrees and converts to radians
float degreesToRadians(float val) {
    return val * (pi / 180);
}

//Takes angle in radians and converts to degrees
float radiansToDegrees(float val) {
    return val * (180 / pi);
}
