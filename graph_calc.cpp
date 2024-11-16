#include <iostream>
#include <vector> 
#include "graph_calc.h"
using namespace std;

vector<int> xPointsListFinder(double leftX, double rightX) {
    vector <int> xPoints;
    double xSpan = rightX - leftX;
    double inc = xSpan/1080;
    for(int i = 0; i <= 1080; i++){
            xPoints.push_back(leftX + inc*i);
    }
    return xPoints;
}

vector<Polyfunc> graphCalc(double a, double b, double c, double leftX, double rightX){
    vector<int> xPointsList = xPointsListFinder(leftX, rightX);
    vector<Polyfunc> pointList;
    for(int i = 0; i <= xPointsList.size(); i++){
        double y = a*(xPointsList[i]^2) + b*xPointsList[i]+ c;
        Polyfunc pointObj(xPointsList[i], y);
        pointList.push_back(pointObj);
    }


    return pointList;
}