#pragma once

#include <string>

enum Operation {
    ADDITION,
    SUBTRACTION,
    MULTIPLICATION,
    DIVISION,
    POWER,
    SQRT
};

class Calculator {
private:
    float leftOperand;
    float rightOperand;
    float result;
    Operation operation;

    std::string leftOp;
    std::string rightOp;

    void ParseString(std::string input);

public:
    Calculator();
    float Calculate(std::string input);
};
