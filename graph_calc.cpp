#include <iostream>
#include <vector> 
#include <graph_calc.h>

vector<int> xPointsListFinder(int leftX, int rightX){
    vector <int> xPoints;
    int xSpan = rightX - leftX;
    double inc = xSpan/1080;
    for(int i = 0; i <= 1080; i++){
            xPoints.pushback(leftX + inc*i);
    }
    return xPoints;
}


vector<Polyfunc> graph_calc(double a, double b, double c, double leftX, double rightX, double bottomY, double topY){
    vector <int> xPointsList = xPointsListFinder(leftX, rightX);
    vector <Polyfunc> pointList;
    for(int i == 0; i <= xPointsList.size(); i++){
        double y = a*(xPointsList(i))^2 + b*xPointsList(i) + c;
        Polyfunc pointObj(xPointsList(i), y);
        pointList.pushback(pointObj);
    }


    return pointList;
}