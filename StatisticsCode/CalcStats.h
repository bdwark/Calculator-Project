#pragma once
#include <vector>
#include <cmath> // For pow()

class CalcStats {
private:
    // Statistical helper operations
    double calculateMeanHelper(const std::vector<double>& numbers);
    double calculateMedianHelper(std::vector<double> numbers);
    double findLowestHelper(const std::vector<double>& numbers);
    double findHighestHelper(const std::vector<double>& numbers);
    double standardDeviationHelper(const std::vector<double>& numbers);

public:
    CalcStats();

    // Statistical operations
    double calculateMean(const std::vector<double>& numbers);
    double calculateMedian(const std::vector<double>& numbers);
    double findLowest(const std::vector<double>& numbers);
    double findHighest(const std::vector<double>& numbers);
    //this is the standard deviation of a population
    double standardDeviation(const std::vector<double>& numbers);
};
