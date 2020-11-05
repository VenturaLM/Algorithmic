/*
*	File:	main.cpp
*	Author:	Ventura Lucena Martínez
*	Email:	i72lumav@uco.es
*/

#include <vector>

#include "matrix.hpp"
#include "exponentiation.hpp"
#include "filesFunctions.hpp"

using namespace std;

int main()
{
	srand(time(NULL));

	vector<double> realTimes_1, realTimes_2, realTimes_3;
	vector<double> nElements;

	int orderMin, orderMax, exponent, increase;
	cout << "Introduce the minimum matrix order: \n> ";
	cin >> orderMin;
	cout << "Introduce the maximum matrix order: \n> ";
	cin >> orderMax;
	cout << "Introduce the increse for order\n> ";
	cin >> increase;
	cout << "Introduce the exponent: \n> ";
	cin >> exponent;
	cout << endl;

	for (auto n = orderMin; n <= orderMax; n+= increase)
	{
		vector< vector<double> > matrix(n, vector<double> (n));
		autofillMatrix(matrix, n);
		//printMatrix(matrix, n);

		cout << "Matrix order = <" << n << ">" << endl;
		method_1(matrix, nElements, realTimes_1, n, exponent);
		method_2(matrix, nElements, realTimes_2, n, exponent);
		method_3(matrix, nElements, realTimes_3, n, exponent);

		nElements.push_back(n);

		cout << endl;
	}

	const string file_name = "Data.txt";
	saveToFile(nElements, realTimes_1, realTimes_2, realTimes_3, file_name);
	cout << "Data saved on [" << file_name << "] successfully." << endl;

	return 0;
}