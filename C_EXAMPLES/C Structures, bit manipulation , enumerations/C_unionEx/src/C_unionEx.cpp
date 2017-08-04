//============================================================================
// Name        : C_unionEx.cpp
// Author      : Cristian Mosquera
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

// number union definition
union number {
int x;
double y;
}; // end union number

int main() {

	union number value; // define union variable
	value.x = 100; // put an integer into the union

	cout << "Put 100 in the integer member" << endl;
	cout << "and print both members." << endl;
	cout << "int: " << endl;
	cout << value.x << endl << endl;
	cout << "double" << endl;
	cout << value.y << endl << endl;

	value.y = 100.0;

	cout << "Put 100 in the floating point member" << endl;
		cout << "and print both members." << endl;
		cout << "int: " << endl;
		cout << value.x << endl << endl;
		cout << "double" << endl;
		cout << value.y << endl;
	return 0;
}
