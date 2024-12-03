#include "CalcStats.h"
#include <vector>
#include <algorithm>
#include <numeric>
#include <stdexcept>
using namespace std;

CalcStats::CalcStats() {}
  
double CalcStats::divideHelper(double a, double b) {
    if (b == 0) {
        throw std::invalid_argument("Division by zero is not allowed.");
    }
    return a / b;
}

// Statistical operations
double CalcStats::calculateMeanHelper(const std::vector<double>& numbers) {
    if (numbers.empty()) {
        throw std::invalid_argument("Cannot calculate mean of an empty vector.");
    }
    double sum = std::accumulate(numbers.begin(), numbers.end(), 0.0);
    return sum / numbers.size();
}

double CalcStats::calculateMedianHelper(const std::vector<double> numbers) {
    if (numbers.empty()) {
        throw std::invalid_argument("Cannot calculate median of an empty vector.");
    }
    std::sort(numbers.begin(), numbers.end());
    size_t n = numbers.size();
    if (n % 2 == 0) {
        return (numbers[n / 2 - 1] + numbers[n / 2]) / 2.0;
    }
    else {
        return numbers[n / 2];
    }
}

double CalcStats::findLowestHelper(const std::vector<double>& numbers) {
    if (numbers.empty()) {
        throw std::invalid_argument("Cannot find lowest value in an empty vector.");
    }
    return *std::min_element(numbers.begin(), numbers.end());
}

double CalcStats::findHighestHelper(const std::vector<double>& numbers) {
    if (numbers.empty()) {
        throw std::invalid_argument("Cannot find highest value in an empty vector.");
    }
    return *std::max_element(numbers.begin(), numbers.end());
}

double CalcStats::standardDeviationHelper(const std::vector<double>& numbers) {
    if (numbers.empty()) {
        throw std::invalid_argument("Cannot find stanard Deviation in an empty vector.");
    }
    double mean = calculateMeanHelper(numbers);
    double total = 0;
    for (int i = 0; i < numbers.size(); i++) {
        total = total + pow((numbers[i] - mean), 2);
    }
    double temp = pow(total/numbers.size(), 1.0 / 2.0);
    return temp;
}

// Statistical operations
// Finds mean
double CalcStats::calculateMean(const std::vector<double>& numbers) { return calculateMeanHelper(numbers); }
// Finds median
double CalcStats::calculateMedian(const std::vector<double>& numbers) { return calculateMedianHelper(numbers); }
// Finds lowest value of a set
double CalcStats::findLowest(const std::vector<double>& numbers) { return findHighestHelper(numbers); }
// Finds highest value of a set
double CalcStats::findHighest(const std::vector<double>& numbers) { return findHighestHelper(numbers); }
// Finds standard deviation of a population
double CalcStats::standardDeviation(const std::vector<double>& numbers) { return stanardDeviationHelper(numbers); }
