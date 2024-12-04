#include "Stats.h"
#include <iostream>
#include <vector>
#include <limits>
#include <sstream>

double stats(std::string stringNumbers, int func) {
    CalcStats calc;
    // string of numbers separated by commas parser
    std::vector<double> numbers;
    std::string curvalue;
    // takes in the string and processes it like an input stream
    std::stringstream ss(stringNumbers);
    while (std::getline(ss, curvalue, ',')) { // Separate each variable per sample from the comma separator
        numbers.push_back(std::stod(curvalue));
    }

    // control flow
    switch (func) {
    case 1:
        return calc.calculateMean(numbers);
    case 2:
        return calc.calculateMedian(numbers);
    case 3:
        return calc.findLowest(numbers);
    case 4:
        return calc.findHighest(numbers);
    case 5:
        return calc.standardDeviation(numbers);
    default:
        return std::numeric_limits<double>::quiet_NaN(); // Return NaN for invalid function
    }
}
