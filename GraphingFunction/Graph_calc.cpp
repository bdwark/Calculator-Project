#include <iostream>
#include <vector> 
#include <cmath>
#include "Graph_calc.h"
using namespace std;

//This takes in the left and right X bounds and the pixel width of the screan
//then it finds the span of numbers it must calculate and finds the value to increment x by
//then it generates a vector of all the x points
vector<double> xPointsListFinder(double leftX, double rightX, int pixels) {
    vector <double> xPoints;
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
//then it creates a pointObj of class polyfunc, which is just a class which contains the point data
//then after adding these points to a vector, it returns this vector 
vector<Polyfunc> graphCalc(double a, double b, double c, double leftX, double rightX, int pixels){
    vector<double> xPointsList = xPointsListFinder(leftX, rightX, pixels);
    vector<Polyfunc> pointList;
    for(int i = 0; i <= xPointsList.size()-1; i++){
        double y = a*pow(xPointsList[i],2) + b*xPointsList[i]+ c;
        Polyfunc pointObj(xPointsList[i], y);
        pointList.push_back(pointObj);
    }
    return pointList;
}
