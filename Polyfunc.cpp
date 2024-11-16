#include "Polyfunc.h"
using namespace std;

Polyfunc::Polyfunc(double tempX, double tempY){
    x = tempX; 
    y = tempY; 
}


double Polyfunc::getX() { return x; }
double Polyfunc::getY() { return y