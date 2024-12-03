#include <iostream>
#include <string>

#include "QuadInequalities.h"
#include "SimplifyExpression.h"

using namespace std;

int main()
{
	// testing solving quadratic inequalities

	string input;
	cout << "Enter distributive to simplify:";
	getline(cin, input);
	cout << quadraticInequality(input);


	// testing distributive property simplification
/* 
	string input;
	cout << "Enter distributive to simplify:";
	getline(cin, input);
	cout << simplifyExpression(input);
*/
	return 0;
}