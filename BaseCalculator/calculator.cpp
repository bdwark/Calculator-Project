#include "calculator.h"

#include <string>
#include <iostream>
#include <cmath>

/* ---------------------------------------------------------------
    Operations are:
        + Addition
        - Subtraction
        (star) Multiplication
        / Division
        ^ Power
        s Square Root (Will only square root number after s)
-------------------------------------------------------------------*/

// Parses through string and sets the left and right operators as strings
void Calculator::ParseString(std::string input) {
    bool foundOp = false;
    char currentChar;

    for (int i = 0; i < input.length(); i++) {
        currentChar = input.at(i);

        // Checks to see if the current character is an operation
        if (input.at(i) != '+' && input.at(i) != '-' && input.at(i) != '*' && input.at(i) != '/' && input.at(i) != '^' && input.at(i) != 's') {
            // If not operation, check if operation has been found
            if (!foundOp) {
                leftOp += currentChar;
            }
            else {
                rightOp += currentChar;
            }
        }
        else {
            foundOp = true;
            if (input.at(i) == '+') {
                operation = ADDITION;
            }
            else if (input.at(i) == '-') {
                operation = SUBTRACTION;
            }
            else if (input.at(i) == '*') {
                operation = MULTIPLICATION;
            }
            else if (input.at(i) == '/') {
                operation = DIVISION;
            }
            else if (input.at(i) == '^') {
                operation = POWER;
            }
            else if (input.at(i) == 's') {
                operation = SQRT;
            }
        }
    }
}

Calculator::Calculator() {}

    // Calculates and returns value as a float
float Calculator::Calculate(std::string input) {
    ParseString(input);

    // If sqrt, only convert right operand
    if (operation == SQRT) {
        rightOperand = std::stof(rightOp);
    }
    else {
        leftOperand = std::stof(leftOp);
        rightOperand = std::stof(rightOp);
    }

    // Operate
    switch (operation) {
    case ADDITION:
        result = leftOperand + rightOperand;
        break;
    case SUBTRACTION:
        result = leftOperand - rightOperand;
        break;
    case MULTIPLICATION:
        result = leftOperand * rightOperand;
        break;
    case DIVISION:
        result = leftOperand / rightOperand;
        break;
    case POWER:
        result = std::pow(leftOperand, rightOperand);
        break;
    case SQRT:
        result = std::sqrt(rightOperand);
        break;
    }

    return result;
}
