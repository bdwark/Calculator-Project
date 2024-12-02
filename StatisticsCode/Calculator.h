#pragma once
#include <vector>
#include <cmath> // For pow()
using namespace std;
class Calculator {
private:
    // Statistical operations
    double calculateMeanHelper(const std::vector<double>& numbers);
    double calculateMedianHelper(std::vector<double> numbers);
    double findLowestHelper(const std::vector<double>& numbers);
    double findHighestHelper(const std::vector<double>& numbers);
    double standardDeviationHelper(const std::vector<double>& numbers);

public:
    Calculator();

    // Statistical operations
    double calculateMean(const std::vector<double>& numbers);
    double calculateMedian(const std::vector<double>& numbers);
    double findLowest(const std::vector<double>& numbers);
    double findHighest(const std::vector<double>& numbers);
    double standardDeviation(const std::vector<double>& numbers);
};
