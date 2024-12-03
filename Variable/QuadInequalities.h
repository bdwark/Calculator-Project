#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <regex>
#include <algorithm>
#include <iomanip>

using namespace std;

// Parses the equation and makes sure its valid
// Returns in parts to then simplify
bool parseInq(const string& input, string& leftSide, string& sign, string& rightSide)
{
	regex pattern1(R"((.*?)([<>]=?|==)(.*))");
	smatch matches;

	if (regex_match(input, matches, pattern1))
	{
		leftSide = matches[1].str();
		sign = matches[2].str();
		rightSide = matches[3].str();

		leftSide.erase(remove(leftSide.begin(), leftSide.end(), ' '), leftSide.end());
		sign.erase(remove(sign.begin(), sign.end(), ' '), sign.end());
		rightSide.erase(remove(rightSide.begin(), rightSide.end(), ' '), rightSide.end());
		return true;
	}

	return false;
}

// checks if the equation is already simplified or not
bool isSimple(const string& equation)
{
	regex simplePattern(R"(^[+-]?\d*\.?\d*x\^2\s*[+-]\s*\d*\.?\d*x\s*[+-]\s*\d*\.?\d*$)");
	
	return regex_match(equation, simplePattern);
}

// Solves quadratic inequalities, where sign relates the inequalities. Returns a formatted string.
string solveQuadInequal(double a, double b, double c, string sign)
{
	stringstream result;

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
			ostringstream oss;
			oss << setprecision(3) << x;
			string xtrim = oss.str();
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
		ostringstream oss;
		oss << setprecision(3) << root;
		string rtrim = oss.str();
		if (sign == "<") { result << (a > 0 ? "No solution" : "All real numbers"); }
		else if (sign == "<=") { result << "x = " << rtrim; }
		else if (sign == ">") { result << (a > 0 ? "All real numbers" : "No Solution"); }
		else if (sign == ">=") { result << "x = " << rtrim; }
	}
	// Two roots
	else
	{
		double rootOne = (-b - sqrt(discriminant)) / (2 * a);
		double rootTwo = (-b + sqrt(discriminant)) / (2 * a);

		if (rootOne > rootTwo) { swap(rootOne, rootTwo); }
		ostringstream oss1, oss2;
		oss1 << setprecision(3) << rootOne;
		string r1trim = oss1.str();
		oss2 << setprecision(3) << rootTwo;
		string r2trim = oss2.str();
		if (sign == "<")
		{
			stringstream temp;
			if (a > 0) { temp << r1trim << " < x < " << r2trim; }
			else { temp << "x < " << r1trim << "or x > " << r2trim; }
			result << temp.str();
		}
		else if (sign == "<=")
		{
			stringstream temp;
			if (a > 0) { temp << r1trim << " <= x <= " << r2trim; }
			else { temp << "x <= " << r1trim << "or x >= " << r2trim; }
			result << temp.str();
		}
		else if (sign == ">")
		{
			stringstream temp;
			if (a > 0) { temp << "x < " << r1trim << " or x > " << r2trim; }
			else { temp << r1trim << " < x < " << r2trim; }
			result << temp.str();
		}
		else if (sign == ">=")
		{
			stringstream temp;
			if (a > 0) { temp << "x <= " << r1trim << " or x >= " << r2trim; }
			else { temp << r1trim << " <= x <= " << r2trim; }
			result << temp.str();
		}
	}

	return result.str();
}

string simplify(const string& input)
{
	string leftSide, sign, rightSide, result;

	// parse input
	if (!parseInq(input, leftSide, sign, rightSide))
	{
		result = "Invalid input";
		return result;
	}

	// subtract right from left side
	string equation;
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

		regex pattern2(R"(([+-]?\s*\d*\.?\d*)(x\^2|x)?)");
		smatch matches;

		string modEquation = equation;
		modEquation.erase(remove(modEquation.begin(), modEquation.end(), ' '), modEquation.end());

		auto start = modEquation.cbegin();
		auto end = modEquation.cend();

		while (regex_search(start, end, matches, pattern2))
		{
			string coeffStr = matches[1].str();
			string variable = matches[2].str();

			if (coeffStr.empty() && variable.empty()) { break; }

			// convert to double
			double coeff = coeffStr.empty() || coeffStr == "+" ? 1 : (coeffStr == "-" ? -1 : stod(coeffStr));

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
		regex product(R"(\((x[+-]\d+)\)\((x[+-]\d+)\))");
		regex binomial(R"(\((x[+-]\d+)\))");

		if (regex_match(leftSide, product))
		{
			smatch pMatch;
			regex_search(leftSide, pMatch, product);

			string factorOne = pMatch[1].str();
			string factorTwo = pMatch[2].str();

			regex factor(R"(x([+-]\d+))");
			smatch fMatch;

			double rootOne = 0, rootTwo = 0;

			if (regex_search(factorOne, fMatch, factor)) { rootOne = -stod(fMatch[1].str()); }
			if (regex_search(factorTwo, fMatch, factor)) { rootTwo = -stod(fMatch[1].str()); }

			if (rootOne > rootTwo) { swap(rootOne, rootTwo); }
			ostringstream oss1, oss2;
			oss1 << setprecision(3) << rootOne;
			string r1trim = oss1.str();
			oss2 << setprecision(3) << rootTwo;
			string r2trim = oss2.str();
			if (sign == ">") { result = "x < " + r1trim + " or x > " + r2trim; }
			else if (sign == ">=") { result = "x <= " + r1trim + " or x >= " + r2trim; }
			else if (sign == "<") { result = r1trim + " < x < " + r2trim; }
			else if (sign == "<=") { result = r1trim + " <= x <= " + r2trim; }

			return result;
		}
		else if (regex_match(leftSide, binomial))
		{
			smatch bMatch;
			regex_search(leftSide, bMatch, binomial);
			string inside = bMatch[1].str();

			regex factor(R"(x([+-]\d+))");
			smatch fMatch;
			double constant = 0;
			if (regex_search(inside, fMatch, factor)) { constant = stod(fMatch[1].str()); }

			double a = 1;
			double b = 2 * constant;
			double c = constant * constant;

			c -= stod(rightSide);

			result = solveQuadInequal(a, b, c, sign);
			return result;
		} 
		else { return result = "Error. Try standard form or flipping."; }
	}
}

string quadraticInequality(const string& input)
{
	string result;
	result = simplify(input);

	return result;
}