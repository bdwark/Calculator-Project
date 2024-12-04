#include <iostream>
#include <string>
#include "TempConversion.h"

/*
    Temperature Converter
    Use far for fahrenheit
    Use cel for celsius
    Use kel for kelvin

    Returns floats
*/

//Takes temperature in Celsius and desired output unit and converts to that unit
float celciusConverter(float val, std::string unitOut) {
    if (unitOut == "far") {
        return (val * (9.0 / 5.0)) + 32.0;
    } else if (unitOut == "kel") {
        return val + 273.15;
    } else {
        return val;
    }
}

//Takes temperature in Fahrenheit and desired output unit and converts to that unit
float farenheitConverter(float val, std::string unitOut) {
    if (unitOut == "cel") {
        return (val - 32) * (5.0 / 9.0);
    } else if (unitOut == "kel") {
        return ((val - 32) * (5.0 / 9.0)) + 273.15;
    } else {
        return val;
    }
}

//Takes temperature in Kelvin and desired output unit and converts to that unit
float kelvinConverter(float val, std::string unitOut) {
    if (unitOut == "cel") {
        if (val == static_cast<float>(273.15)) {
            return static_cast<float>(0);
        } else {
            return val - 273.15;
        }
    } else if (unitOut == "far") {
        return (val - 273.15) * (9.0 / 5.0) + 32;
    } else {
        return val;
    }
}
