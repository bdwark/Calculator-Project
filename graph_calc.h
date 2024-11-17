#pragma once
using namespace std;

#include "Polyfunc.h"
#include <vector>

// Function declarations
vector<double> xPointsListFinder(double tempLeftX, double tempRightX);
vector<Polyfunc> graphCalc(double a, double b, double c, double leftX, double rightX);
