#pragma once

#include <iostream>
#include <string>

/*
    Temperature Converter
    Use far for fahrenheit
    Use cel for celsius
    Use kel for kelvin

    Returns floats
*/

float celciusConverter(float val, std::string unitOut);

float farenheitConverter(float val, std::string unitOut);

float kelvinConverter(float val, std::string unitOut);
