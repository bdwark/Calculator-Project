#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <cmath>

class Calculator {
private:
    CombinedOperations combinedOps;

public:
    // Basic operations
    double add(double a, double b) { return combinedOps.add(a, b); }
    double subtract(double a, double b) { return combinedOps.subtract(a, b); }
    double multiply(double a, double b) { return combinedOps.multiply(a, b); }
    double divide(double a, double b) { return combinedOps.divide(a, b); }
    double exponentiate(double base, double exponent) { return std::pow(base, exponent); }
    double radical(double value, double root) { return std::pow(value, 1.0 / root); }

    // Statistical operations
    double calculateMean(const std::vector<double>& numbers) { return combinedOps.calculateMean(numbers); }
    double calculateMedian(const std::vector<double>& numbers) { return combinedOps.calculateMedian(numbers); }
    double findLowest(const std::vector<double>& numbers) { return combinedOps.findLowest(numbers); }
    double findHighest(const std::vector<double>& numbers) { return combinedOps.findHighest(numbers); }
};

#endif


