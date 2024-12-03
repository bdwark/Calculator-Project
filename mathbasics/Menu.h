#ifndef MENU_H
#define MENU_H

#include "Calculator.h"

// Function declarations
void displayMainMenu(); // displays the options in the main menu 
void handleBasicOperations(Calculator& calc); // holds the functions of the basic math operations like multiplication, additions or division
void handleStatisticalOperations(Calculator& calc); // holds the functions of the statiscal operations to find stuff like the mean or median of the multiple values

#endif


