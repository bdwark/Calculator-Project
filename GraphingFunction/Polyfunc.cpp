#include "Polyfunc.h"

//Polyfunc constructor 
Polyfunc::Polyfunc(double tempX, double tempY){
    x = tempX; 
    y = tempY; 
}

//two functions for geting the X and Y data
double Polyfunc::getX() { return x; }
double Polyfunc::getY() { return y; }
