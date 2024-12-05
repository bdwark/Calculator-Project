#pragma once

//simple point object to bundle the X and Y data
class Polyfunc {
public:
    Polyfunc(double tempX, double tempY);
    double getX();
    double getY();
private: 
    double x;
    double y;
};
