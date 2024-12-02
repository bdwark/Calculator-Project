#include "Menu.h"
#include <iostream>
#include <vector>
#include <limits>
#include <sstream>
using namespace std;

double stats(string stringNumbers, int func){
    Calculator calc;
    //make parser for string of numbers seperate by commas
    vector<double> numbers;
    string curvalue;
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
        return calc.stanardDeviation(numbers);
    }


}