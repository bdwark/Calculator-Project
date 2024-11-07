#include <string>
#include <iostream>
#include <cmath>

using namespace std;

/*
    Angle Conversions
    Returns floats
*/

float pi = 2 * acos(0);

float degreesToRadians (float val) {
    return val * (pi/180);
}

float radiansToDegrees (float val) {
    return val * (180/pi);
}
