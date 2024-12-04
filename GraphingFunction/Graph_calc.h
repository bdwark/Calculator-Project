#pragma once

#include "Polyfunc.h"
#include <vector>

// Function declarations
std::vector<double> xPointsListFinder(double tempLeftX, double tempRightX, int pixels);
std::vector<Polyfunc> graphCalc(double a, double b, double c, double leftX, double rightX, int pixels);
