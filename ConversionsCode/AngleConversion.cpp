#include <string>
#include <iostream>
#include <cmath>
#include "AngleConversion.h"

using namespace std;

/*
    Angle Conversions
    Returns floats
*/

float pi = 2 * acos(0);

//Takes angle in degrees and converts to raidans
float degreesToRadians (float val) {
    return val * (pi/180);
}

//Takes angle in raidans and converts to degrees
float radiansToDegrees (float val) {
    return val * (180/pi);
}
