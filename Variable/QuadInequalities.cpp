#include "QuadInequalities.h"
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <regex>
#include <algorithm>
#include <iomanip>

// Parses the equation and makes sure its valid
// Returns in parts to then simplify
bool parseInq(const std::string& input, std::string& leftSide, std::string& sign, std::string& rightSide)
{
    std::regex pattern1(R"((.*?)([<>]=?|==)(.*))");
    std::smatch matches;

    if (std::regex_match(input, matches, pattern1))
    {
        leftSide = matches[1].str();
        sign = matches[2].str();
        rightSide = matches[3].str();

        leftSide.erase(std::remove(leftSide.begin(), leftSide.end(), ' '), leftSide.end());
        sign.erase(std::remove(sign.begin(), sign.end(), ' '), sign.end());
        rightSide.erase(std::remove(rightSide.begin(), rightSide.end(), ' '), rightSide.end());
        return true;
    }

    return false;
}

// checks if the equation is already simplified or not
bool isSimple(const std::string& equation)
{
    std::regex simplePattern(R"(^[+-]?\d*\.?\d*x\^2\s*[+-]\s*\d*\.?\d*x\s*[+-]\s*\d*\.?\d*$)");
    
    return std::regex_match(equation, simplePattern);
}

// Solves quadratic inequalities, where sign relates the inequalities. Returns a formatted string.
std::string solveQuadInequal(double a, double b, double c, std::string sign)
{
    std::stringstream result;

    // handle linear cases
    if (a == 0)
    {
        if (b == 0)
        {
            if ((sign == "<" || sign == "<=") && c == 0)
            {
                result << "No real solution";
            }
            else if ((sign == ">" || sign == ">=") && c == 0)
            {
                result << "All real numbers";
            }

            return result.str();
        }
        else
        {
            double x = -c / b;
            std::ostringstream oss;
            oss << std::setprecision(3) << x;
            std::string xtrim = oss.str();
            if (sign == "<") { result << "x < " << xtrim; }
            else if (sign == "<=") { result << "x <= " << xtrim; }
            else if (sign == ">") { result << "x > " << xtrim; }
            else if (sign == ">=") { result << "x >= " << xtrim; }

            return result.str();
        }
    }

    double discriminant = b * b - 4 * a * c;

    // No roots
    if (discriminant < 0)
    {
        if (sign == "<" || sign == "<=")
        {
            result << (a < 0 ? "All real numbers" : "No real solution");
        }
        else if (sign == ">" || sign == ">=")
        {
            result << (a > 0 ? "All real numbers" : "No real solution");
        }
    }
    // One root
    else if (discriminant == 0)
    {
        double root = -b / (2 * a);
        std::ostringstream oss;
        oss << std::setprecision(3) << root;
        std::string rtrim = oss.str();
        if (sign == "<") { result << (a > 0 ? "No solution" : "All real numbers"); }
        else if (sign == "<=") { result << "x = " << rtrim; }
        else if (sign == ">") { result << (a > 0 ? "All real numbers" : "No Solution"); }
        else if (sign == ">=") { result << "x = " << rtrim; }
    }
    // Two roots
    else
    {
        double rootOne = (-b - std::sqrt(discriminant)) / (2 * a);
        double rootTwo = (-b + std::sqrt(discriminant)) / (2 * a);

        if (rootOne > rootTwo) { std::swap(rootOne, rootTwo); }
        std::ostringstream oss1, oss2;
        oss1 << std::setprecision(3) << rootOne;
        std::string r1trim = oss1.str();
        oss2 << std::setprecision(3) << rootTwo;
        std::string r2trim = oss2.str();
        if (sign == "<")
        {
            std::stringstream temp;
            if (a > 0) { temp << r1trim << " < x < " << r2trim; }
            else { temp << "x < " << r1trim << "or x > " << r2trim; }
            result << temp.str();
        }
        else if (sign == "<=")
        {
            std::stringstream temp;
            if (a > 0) { temp << r1trim << " <= x <= " << r2trim; }
            else { temp << "x <= " << r1trim << "or x >= " << r2trim; }
            result << temp.str();
        }
        else if (sign == ">")
        {
            std::stringstream temp;
            if (a > 0) { temp << "x < " << r1trim << " or x > " << r2trim; }
            else { temp << r1trim << " < x < " << r2trim; }
            result << temp.str();
        }
        else if (sign == ">=")
        {
            std::stringstream temp;
            if (a > 0) { temp << "x <= " << r1trim << " or x >= " << r2trim; }
            else { temp << r1trim << " <= x <= " << r2trim; }
            result << temp.str();
        }
    }

    return result.str();
}

std::string simplify(const std::string& input)
{
    std::string leftSide, sign, rightSide, result;

    // parse input
    if (!parseInq(input, leftSide, sign, rightSide))
    {
        result = "Invalid input";
        return result;
    }

    // subtract right from left side
    std::string equation;
    if (rightSide == "0")
    {
        equation = leftSide;
    }
    else
    {
        equation = leftSide + " - " + rightSide;
    }

    // check if its simplified first
    if (isSimple(equation))
    {
        double a = 0, b = 0, c = 0;

        std::regex pattern2(R"(([+-]?\s*\d*\.?\d*)(x\^2|x)?)");
        std::smatch matches;

        std::string modEquation = equation;
        modEquation.erase(std::remove(modEquation.begin(), modEquation.end(), ' '), modEquation.end());

        auto start = modEquation.cbegin();
        auto end = modEquation.cend();

        while (std::regex_search(start, end, matches, pattern2))
        {
            std::string coeffStr = matches[1].str();
            std::string variable = matches[2].str();

            if (coeffStr.empty() && variable.empty()) { break; }

            // convert to double
            double coeff = coeffStr.empty() || coeffStr == "+" ? 1 : (coeffStr == "-" ? -1 : std::stod(coeffStr));

            if (variable == "x^2") { a += coeff; }
            else if (variable == "x") { b += coeff; }
            else if (variable.empty()) { c += coeff; }

            start = matches.suffix().first;
        }
        
        result = solveQuadInequal(a, b, c, sign);
        return result;
    }
    // if not, simplify
    else
    {
        // regex to check for which type of expression it is
        std::regex product(R"(\((x[+-]\d+)\)\((x[+-]\d+)\))");
        std::regex binomial(R"(\((x[+-]\d+)\))");

        if (std::regex_match(leftSide, product))
        {
            std::smatch pMatch;
            std::regex_search(leftSide, pMatch, product);

            std::string factorOne = pMatch[1].str();
            std::string factorTwo = pMatch[2].str();

            std::regex factor(R"(x([+-]\d+))");
            std::smatch fMatch;

            double rootOne = 0, rootTwo = 0;

            if (std::regex_search(factorOne, fMatch, factor)) { rootOne = -std::stod(fMatch[1].str()); }
            if (std::regex_search(factorTwo, fMatch, factor)) { rootTwo = -std::stod(fMatch[1].str()); }

            if (rootOne > rootTwo) { std::swap(rootOne, rootTwo); }
            std::ostringstream oss1, oss2;
            oss1 << std::setprecision(3) << rootOne;
            std::string r1trim = oss1.str();
            oss2 << std::setprecision(3) << rootTwo;
            std::string r2trim = oss2.str();
            if (sign == ">") { result = "x < " + r1trim + " or x > " + r2trim; }
            else if (sign == ">=") { result = "x <= " + r1trim + " or x >= " + r2trim; }
            else if (sign == "<") { result = r1trim + " < x < " + r2trim; }
            else if (sign == "<=") { result = r1trim + " <= x <= " + r2trim; }

            return result;
        }
        else if (std::regex_match(leftSide, binomial))
        {
            std::smatch bMatch;
            std::regex_search(leftSide, bMatch, binomial);
            std::string inside = bMatch[1].str();

            std::regex factor(R"(x([+-]\d+))");
            std::smatch fMatch;
            double constant = 0;
            if (std::regex_search(inside, fMatch, factor)) { constant = std::stod(fMatch[1].str()); }

            double a = 1;
            double b = 2 * constant;
            double c = constant * constant;

            c -= std::stod(rightSide);

            result = solveQuadInequal(a, b, c, sign);
            return result;
        } 
        else { return result = "Error. Try standard form or flipping."; }
    }
}

std::string quadraticInequality(const std::string& input)
{
    std::string result;
    result = simplify(input);

    return result;
}
