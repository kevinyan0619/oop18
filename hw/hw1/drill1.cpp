//============================================================================
// Name        : OOPhw1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {

	int a = 130;
	double b = 140.43;
	char c = 'd';
	bool d = false;

	int g = (int) b;
	double h = (double) g;
	cout << "double to int: " << b << "->(cast)->" << g << "->(convert back)->"
			<< h << '\n';

	char i = (char) b;
	double j = (double) i;
	cout << "double to char: " << b << "->(cast)->" << i << "->(convert back)->"
			<< j << '\n';

	bool k = (bool) b;
	double l = (double) k;
	cout << "double to bool: " << b << "->(cast)->" << k << "->(convert back)->"
			<< l << '\n';

	char m = (char) a;
	int n = (int) m;
	cout << "int to char: " << a << "->(cast)->" << m << "->(convert back)->"
			<< n << '\n';

	bool o = (bool) a;
	int p = (int) o;
	cout << "int to bool: " << a << "->(cast)->" << o << "->(convert back)->"
			<< p << '\n';

	bool e = (bool) c;
	char f = (char) e;
	cout << "char to bool: " << c << "->(cast)->" << e << "->(convert back)->"
			<< f << '\n';

	return 0;
}
