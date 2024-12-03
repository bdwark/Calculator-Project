#include "Stats.h"
#include <iostream>
#include <vector>
#include <limits>
#include <sstream>
using namespace std;

double stats(string stringNumbers, int func){
    CalcStats calc;
    // string of numbers seperated by commas parser
    vector<double> numbers;
    string curvalue;
    // takes in the string and process it like a input stream
    stringstream ss(stringNumbers);
    while (getline(ss, curvalue, ',')) { //Separate each variable per sample from the comma separator
        numbers.push_back(stod(curvalue));
    }
    //control flow
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
    }


}
