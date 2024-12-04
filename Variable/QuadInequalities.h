#ifndef EQUATION_SOLVER_H
#define EQUATION_SOLVER_H

#include <string>
#include <sstream>
#include <vector>

// Parses the equation and makes sure it's valid
// Returns in parts to then simplify
bool parseInq(const std::string& input, std::string& leftSide, std::string& sign, std::string& rightSide);

// Checks if the equation is already simplified or not
bool isSimple(const std::string& equation);

// Solves quadratic inequalities, where sign relates to the inequalities. Returns a formatted string.
std::string solveQuadInequal(double a, double b, double c, std::string sign);

// Simplifies the given equation or returns an error message
std::string simplify(const std::string& input);

// Main function to handle quadratic inequality input
std::string quadraticInequality(const std::string& input);

#endif // EQUATION_SOLVER_H
