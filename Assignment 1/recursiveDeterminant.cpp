/*
*	File:	recursiveDeterminant.cpp
*	Author:	Ventura Lucena Martínez
*	Email:	i72lumav@uco.es
*/

#include <vector>

#include "determinants.hpp"
#include "sistemaEcuaciones.hpp"
#include "statisticsFunctions.hpp"
#include "filesFunctions.hpp"
#include "ClaseTiempo.cpp"

using namespace std;

/*---------------------
*	Matrix operations:
---------------------*/
void getMatrixCofactor(vector< vector<double> > &matrix, vector< vector<double> > &aux, int p, int q, double n)
{
	int i = 0, j = 0;

	for (auto row = 0; row < n; row++)
	{
		for (auto col = 0; col < n; col++)
		{
			if(i != p and j != q)
			{
				aux[i][j++] = matrix[row][col];

				if(j == n - 1)
				{
					j = 0;
					i++;
				}
			}
		}
	}
}

double calculateRecursiveDeterminant(vector< vector<double> > &matrix, const double &n)
{
	double determinant = 0.0;

	if(n == 1)
		return matrix[0][0];

	vector< vector<double> > aux(n, vector<double> (n));
	int sign = 1;

	for (auto i = 0; i < n; i++)
	{
		getMatrixCofactor(matrix, aux, 0, i, n);
		determinant += sign * matrix[0][i] * calculateRecursiveDeterminant(aux, n - 1);
		sign = -sign;
	}

	return determinant;
}

/*---------------------
*	R. determinant:
---------------------*/
void recursiveDeterminant()
{
	srand(time(NULL));
	Clock time;

	vector<double> realTimes;
	vector<double> nElements;

	int orderMin, orderMax, increase;

	cout << "\nIntroduce minimun order:\n> ";
	cin >> orderMin;
	cout << "\nIntroduce maximun order:\n> ";
	cin >> orderMax;
	cout << "\nIntroduce the increse for order\n> ";
	cin >> increase;
	cout << endl;

	for (auto n = orderMin; n <= orderMax; n += increase)
	{
		vector< vector<double> > matrix(n, vector<double> (n));

		autofillMatrix(matrix, n);
		//printMatrix(matrix, n);
		
		time.start();
		double determinant = calculateRecursiveDeterminant(matrix, n);

		if (time.isStarted())
			time.stop();

		realTimes.push_back(time.elapsed());
		nElements.push_back(n);

		cout << "n = <" << n << "> time: " << time.elapsed() << " microseconds." << endl;
	}

	vector<double> a;
	for (auto i = 0; i < 2; i++)
		a.push_back(0.0);

	factorialAdjustment(nElements, realTimes, a);

	vector<double> estimatedTimes;
	calculateEstimatedTimesFactorial(nElements, a, estimatedTimes);
	saveToFile(nElements, realTimes, estimatedTimes, "recursive_determinant_data.txt");
	cout << "\nCoefficient of Determination:\n" << coefficientOfDetermination(realTimes, estimatedTimes) << endl;

	cout << "\nDo you want to calculate an estimation for n?\n1. Yes.\n2. No.\n> ";
	int option;
	cin >> option;
	switch(option)
	{
		case 1:
			cout << "\nn value:\n> ";
			double n_value;
			cin >> n_value;
			cout << "\nEstimated time:" << endl;
			calculateEstimatedTimeFactorial(n_value, a);
		break;

		default:
		break;
	}
}