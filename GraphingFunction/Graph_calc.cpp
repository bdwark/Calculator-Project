#include <iostream>
#include <vector> 
#include <cmath>
#include "Graph_calc.h"

//This takes in the left and right X bounds and the pixel width of the screan
//then it finds the span of numbers it must calculate and finds the value to increment x by
//then it generates a vector of all the x points
std::vector<double> xPointsListFinder(double leftX, double rightX, int pixels) {
    std::vector <double> xPoints;
    double xSpan = rightX - leftX;
    double inc = xSpan/pixels;
    for(int i = 0; i <= pixels; i++){
            xPoints.push_back(leftX + inc*i);
    }
    return xPoints;
}

//this takes in the polynomial function and the left and right x bounds, and the pixel width of the screen
//it then parses these numbers and calls xPointsListFinder to return the list of x points
//it then takes these x points and calculates the y points
//then it creates the point
std::vector<Polyfunc> graphCalc(double a, double b, double c, double leftX, double rightX, int pixels){
    std::vector<double> xPointsList = xPointsListFinder(leftX, rightX, pixels);
    std::vector<Polyfunc> pointList;
    for(int i = 0; i <= xPointsList.size()-1; i++){
        double y = a*pow(xPointsList[i],2) + b*xPointsList[i] + c;
        Polyfunc pointObj(xPointsList[i], y);
        pointList.push_back(pointObj);
    }

    return pointList;
}
