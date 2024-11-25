#include <iostream>
#include <string>
#include "TempConversion.h"

using namespace std;

/*
    Temperature Converter
    Use far for farenheit
    Use cel for celsius
    Use kel for kelvin

    Returns floats
*/

float celciusConverter (float val, string unitOut){
    if (unitOut == "far") {
        return (val * (9.0 / 5.0)) + 32.0;
    } else if (unitOut == "kel") {
        return val + 273.15;
    } else {
        return val;
    }
}

float farenheitConverter (float val, string unitOut) {
    if (unitOut == "cel") {
        return (val - 32) * (5.0/9.0);
    } else if (unitOut == "kel") {
        return ((val - 32) * (5.0/9.0)) + 273.15;
    } else {
        return val;
    }
}

float kelvinConverter (float val, string unitOut) {
    if (unitOut == "cel") {
        if (val == static_cast<float>(273.15)) {
            return static_cast<float>(0);
        } else {
            return val - 273.15;
        }
    } else if (unitOut == "far") {
        return (val - 273.15) * (9.0/5.0) + 32;
    } else {
        return val;
    }
}
