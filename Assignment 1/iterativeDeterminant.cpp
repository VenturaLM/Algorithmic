/*
*	File:	iterativeDeterminant.cpp
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
void autofillMatrix(vector< vector<double> > &matrix, const int &order)
{
	for (auto i = 0; i < order; i++)
	{
		for (auto j = 0; j < order; j++)
			matrix[i][j] = 0.95 + (rand() / (RAND_MAX / (1.05 - 0.95)));
	}
}

void printMatrix(const vector< vector<double> > &matrix, const int &order)
{
	cout << endl;
	for (auto i = 0; i < order; i++)
	{
		for (auto j = 0; j < order; j++)
		{
			cout << "[" << matrix[i][j] << "]\t";
		}

		cout << endl;
	}
}

double calculateIterativeDeterminant(vector< vector<double> > &matrix, const double &n)
{
	vector< vector<double> > inversa(n, vector< double >(n));
	inicializarInversa(inversa);
	trianguloInferior(matrix, inversa);
	return productoDiagonal(matrix);
}

/*---------------------
*	I. determinant:
---------------------*/
void iterativeDeterminant()
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
		double determinant = calculateIterativeDeterminant(matrix, n);

		if (time.isStarted())
			time.stop();

		realTimes.push_back(time.elapsed());
		nElements.push_back(n);

		cout << "n = <" << n << "> time: " << time.elapsed() << " microseconds." << endl;
	}

	vector<double> a;
	for (auto i = 0; i < 4; i++)
		a.push_back(0.0);

	polynomialAdjustment(nElements, realTimes, a);

	vector<double> estimatedTimes;
	calculateEstimatedTimesPolynomial(nElements, a, estimatedTimes);
	saveToFile(nElements, realTimes, estimatedTimes, "iterative_determinant_data.txt");
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
			calculateEstimatedTimePolynomial(n_value, a);
		break;

		default:
		break;
	}
}