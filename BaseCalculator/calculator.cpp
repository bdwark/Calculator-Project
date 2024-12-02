#include <string>
#include <iostream>
#include <cmath>


using namespace std;

enum Operation {
    ADDITION,
    SUBTRACTION,
    MULTIPLICATION,
    DIVISION,
    POWER,
    SQRT
};

/* ---------------------------------------------------------------
    Operations are:
        + Addition
        - Subtraction
        (star) Multiplication
        / Division
        ^ Power
        s Square Root (Will only square root number after s)
-------------------------------------------------------------------*/

class Calculator {
private:
    float leftOperand;
    float rightOperand;
    float result;
    Operation operation;

    string leftOp;
    string rightOp;

    //Parses through string and sets the left and right operators as strings
    void ParseString(string input) {
        bool foundOp = false;
        char currentChar;

        for (int i = 0; i < input.length(); i++) {
            currentChar = input.at(i);

            //Checks to see if the current character is an operation
            if (input.at(i) != '+' && input.at(i) != '-' && input.at(i) != '*' && input.at(i) != '/' && input.at(i) != '^' && input.at(i) != 's') {
                //If not operation, check if operation has been found
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

public:

    //Calculates and returns value as a float
    float Calculate(string input) {
        ParseString(input);

        //If sqrt, only convert right operand
        if (operation == SQRT) {
            rightOperand = stof(rightOp);
        }
        else {
            leftOperand = stof(leftOp);
            rightOperand = stof(rightOp);
        }

        //Operate
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
            result = pow(leftOperand, rightOperand);
            break;
        case SQRT:
            result = sqrt(rightOperand);
            break;
        }

        return result;
    }
};
