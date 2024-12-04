#include "SimplifyExpression.h"
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>

bool isMono(const std::string& expr)
{
    size_t pos = 0;
    if (expr[pos] == '+' || expr[pos] == '-') { pos++; }
    if (expr.find('+', pos) != std::string::npos || expr.find('-', pos) != std::string::npos) { return false; }

    return true;
}

// parse input into monomial and binomial
void parseEx(const std::string& exp, std::string& monoString, std::string& biString, std::string& result)
{
    std::string expr = exp;
    //remove spaces
    expr.erase(std::remove(expr.begin(), expr.end(), ' '), expr.end());
    
    size_t firstP1 = expr.find('(');
    size_t lastP1 = expr.find(')');

    // if no parentheses
    if (firstP1 == std::string::npos || lastP1 == std::string::npos || lastP1 <= firstP1)
    { result = "Invalid Expression"; }

    size_t firstP2 = expr.find('(', lastP1 + 1);
    size_t lastP2 = expr.find(')', firstP2);

    if (firstP2 == std::string::npos || lastP2 == std::string::npos)
    {
        // one set of paren
        if (firstP1 == 0)
        {
            // if first is ( then binomial
            biString = expr.substr(firstP1 + 1, lastP1 - firstP1 - 1);
            monoString = expr.substr(lastP1 + 1);

            if (monoString.empty()) { monoString = "1"; }
        }
        // else monomial first then binomial
        else 
        {
            monoString = expr.substr(0, firstP1);
            biString = expr.substr(firstP1 + 1, lastP1 - firstP1 - 1);
        }
    }
    // else two parentheses sets
    else
    {
        // separate sets
        std::string factor1 = expr.substr(firstP1, lastP1 - firstP1 + 1);
        std::string factor2 = expr.substr(firstP2, lastP2 - firstP2 + 1);

        // remove paren
        std::string factorInside1 = factor1.substr(1, factor1.length() - 2);
        std::string factorInside2 = factor2.substr(1, factor2.length() - 2);

        // find monomial
        bool factor1Mono = isMono(factorInside1);
        bool factor2Mono = isMono(factorInside2);

        if (factor1Mono && !factor2Mono)
        {
            monoString = factorInside1;
            biString = factorInside2;
        }
        else if (!factor1Mono && factor2Mono)
        {
            monoString = factorInside2;
            biString = factorInside1;
        }
        else { result = "Error parsing"; }
    }
}

// Parse monomial into int
int parseMono(const std::string& monoString, int& result)
{
    if (monoString.empty()) { return 1; }
    try
    {
        size_t idx;
        int coeff = std::stoi(monoString, &idx);
        if (idx != monoString.length()) { return result = 1; }

        return coeff;
    }
    catch (const std::exception& e) { return result = 1; }
}

void parseBi(const std::string& biString, std::vector<std::string>& termStrings)
{
    std::string bs = biString;
    size_t i = 0;
    size_t len = bs.length();

    while (i < len)
    {
        // check for operator
        char op = '+';
        if (bs[i] == '+' || bs[i] == '-')
        {
            op = bs[i];
            i++;
        }
        else if (i != 0) { break; }

        // get term
        size_t termStart = i;
        while (i < len && bs[i] != '+' && bs[i] != '-') { i++; }
        if (termStart == i) { break; }

        // build
        std::string tsBuild = bs.substr(termStart, i - termStart);
        if (op == '+' && termStrings.empty()) { /* do nothing */ }
        else { tsBuild = op + tsBuild; }

        termStrings.push_back(tsBuild);
    }
}

// parse the terms
void parseTerm(const std::string& termStrings, int& coeff, std::string& variable)
{
    std::string ts = termStrings;
    size_t len = ts.length();
    size_t i = 0;

    coeff = 0;
    variable = "";

    // check for a sign
    int sign = 1;
    if (ts[0] == '+') { sign = 1; i++; }
    else if (ts[0] == '-') { sign = -1; i++; }

    // check coefficient
    int coeffCheck = 0;
    bool coeffFound = false;
    while (i < len && std::isdigit(ts[i]))
    {
        coeffFound = true;
        coeffCheck = coeffCheck * 10 + (ts[i] - '0');
        i++;
    }
    if (!coeffFound) { coeffCheck = 1; }

    coeffCheck *= sign;

    // check variable
    if (i < len) { variable = ts.substr(i); }

    coeff = coeffCheck;
}

// main function to simplify the expression
std::string simplifyEx(const std::vector<int>& resultCoeff, const std::vector<std::string>& termVars)
{
    std::string result;

    for (size_t i = 0; i < resultCoeff.size(); ++i)
    {
        int coeff = resultCoeff[i];
        std::string variable = termVars[i];

        if (coeff == 0) { continue; }

        std::string termString;

        bool isNeg = coeff < 0;
        int absCoeff = std::abs(coeff);

        //check sign
        if (result.empty())
        {
            if (isNeg) { termString += '-'; }
        }
        else { termString += isNeg ? " - " : " + "; }

        if (absCoeff != 1 || variable.empty()) { termString += std::to_string(absCoeff); }
        else if (absCoeff == 1 && variable.empty()) { termString += '1'; }

        termString += variable;

        result += termString;
    }

    if (result.empty()) { result = "0"; }

    return result;
}

std::string simplifyExpression(const std::string& inputs)
{
    std::string exp = inputs;
    std::string monoString, biString, result;
    int resultint = 0;
    parseEx(exp, monoString, biString, result);

    if (!result.empty()) { return result; }

    int monoCoeff = parseMono(monoString, resultint);
    if (resultint == 1) { return result = "Invalid coefficient"; }

    std::vector<std::string> termStrings;
    parseBi(biString, termStrings);

    std::vector<int> termCoefficienct;
    std::vector<std::string> termVars;

    for (size_t i = 0; i < termStrings.size(); ++i)
    {
        int coeff;
        std::string variable;

        parseTerm(termStrings[i], coeff, variable);
        termCoefficienct.push_back(coeff);
        termVars.push_back(variable);
    }

    std::vector<int> resultCoeff;
    for (size_t i = 0; i < termCoefficienct.size(); ++i)
    {
        int res = monoCoeff * termCoefficienct[i];
        resultCoeff.push_back(res);
    }

    result = simplifyEx(resultCoeff, termVars);

    return result;
}
