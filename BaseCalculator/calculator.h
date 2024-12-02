#include <string>

using namespace std;

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

    string leftOp;
    string rightOp;

    void ParseString(string input);

public:
    float Calculate(string input);
};
