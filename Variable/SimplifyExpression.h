#ifndef SIMPLIFY_EXPRESSION_H
#define SIMPLIFY_EXPRESSION_H

#include <string>
#include <vector>

// Checks if the given expression is a monomial
bool isMono(const std::string& expr);

// Parses the expression into a monomial and binomial
void parseEx(const std::string& exp, std::string& monoString, std::string& biString, std::string& result);

// Parses a monomial expression into an integer coefficient
int parseMono(const std::string& monoString, int& result);

// Parses a binomial expression into individual terms
void parseBi(const std::string& biString, std::vector<std::string>& termStrings);

// Parses a single term into its coefficient and variable
void parseTerm(const std::string& termStrings, int& coeff, std::string& variable);

// Simplifies the expression by combining like terms
std::string simplifyEx(const std::vector<int>& resultCoeff, const std::vector<std::string>& termVars);

// Main function to simplify the input expression
std::string simplifyExpression(const std::string& inputs);

#endif // SIMPLIFY_EXPRESSION_H
