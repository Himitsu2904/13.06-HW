#include <iostream>
#include "matrix.h"
using namespace std;

int main()
{
	matrix<double> m1(3, 4);
	m1.show();
	cout << endl << endl;

	matrix<double> m2 = move(m1);
	m2.show();
	cout << endl << endl;

	cout << endl;
}