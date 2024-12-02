#pragma once
#include <vector>
#include <cmath> // For pow()
using namespace std;
class Calculator {
private:
    double addHelper(double a, double b);
    double subtractHelper(double a, double b);
    double multiplyHelper(double a, double b);
    double divideHelper(double a, double b);

    // Statistical operations
    double calculateMeanHelper(const std::vector<double>& numbers);
    double calculateMedianHelper(std::vector<double> numbers);
    double findLowestHelper(const std::vector<double>& numbers);
    double findHighestHelper(const std::vector<double>& numbers);
    double stanardDeviationHelper(const std::vector<double>& numbers);

public:
    Calculator();
    // Basic operations
    double add(double a, double b);
    double subtract(double a, double b);
    double multiply(double a, double b);
    double divide(double a, double b);
    double exponentiate(double base, double exponent);
    double radical(double value, double root);

    // Statistical operations
    double calculateMean(const std::vector<double>& numbers);
    double calculateMedian(const std::vector<double>& numbers);
    double findLowest(const std::vector<double>& numbers);
    double findHighest(const std::vector<double>& numbers);
    double stanardDeviation(const std::vector<double>& numbers);
};
