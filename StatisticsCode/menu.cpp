#include "Menu.h"
#include <iostream>
#include <vector>
#include <limits>
#include <sstream>

double stats(string stringNumbers, int func){
    Calculator calc;
    //make parser for string of numbers seperate by commas
    vector<double> numbers;
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
        return calc.stanardDeviation(numbers);
    }


}