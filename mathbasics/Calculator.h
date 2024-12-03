#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <cmath> // needed for std::pow

class Calculator {
private:
    CombinedOperations combinedOps; 

public:
    // Basic operations
    double add(double a, double b) { return combinedOps.add(a, b); } // returns basic sum of two numbers
    double subtract(double a, double b) { return combinedOps.subtract(a, b); } // returns basic result of b subtracted from a
    double multiply(double a, double b) { return combinedOps.multiply(a, b); } // returns product
    double divide(double a, double b) { return combinedOps.divide(a, b); }  // returns result of a divided by b
    double exponentiate(double base, double exponent) { return std::pow(base, exponent); } // returns the value of a base value with an exponent
    double radical(double value, double root) { return std::pow(value, 1.0 / root); } // returns the root of a number

    // Statistical operations
    double calculateMean(const std::vector<double>& numbers) { return combinedOps.calculateMean(numbers); } // returns the average of the list numbers
    double calculateMedian(const std::vector<double>& numbers) { return combinedOps.calculateMedian(numbers); } // returns the middle value from a list
    double findLowest(const std::vector<double>& numbers) { return combinedOps.findLowest(numbers); } // returns the smallest number from a list
    double findHighest(const std::vector<double>& numbers) { return combinedOps.findHighest(numbers); } // returns the largest number from a list
};

#endif


