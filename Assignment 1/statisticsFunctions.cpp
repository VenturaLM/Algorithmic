/*
*	File:	statisticsFunctions.cpp
*	Author:	Ventura Lucena Martínez
*	Email:	i72lumav@uco.es
*/

#include <cmath>

#include "statisticsFunctions.hpp"
#include "sistemaEcuaciones.hpp"
#include "filesFunctions.hpp"

using namespace std;

/*---------------------
*	Operations:
---------------------*/
double summation(vector<double> &n, const vector<double> &t, int expN, int expT)
{
	double sum = 0.0;
	for (auto i = 0; i < n.size(); i++)
		sum += (pow(n[i], expN) * pow(t[i], expT));

	return sum;
}

void fillMatrixSystemEquations(vector< vector<double> > &A, vector< vector<double> > &B, vector<double> &n, const vector<double> &realTimes, int order)
{
	for (auto i = 0; i < order; i++)
		for (auto j = 0; j < order; j++)
			A[i][j] = summation(n, realTimes, i + j, 0);

	A[0][0] = n.size();

	for (auto i = 0; i < order; i++)
		B[i][0] = summation(n, realTimes, i, 1);
}

double timesSummation(const vector<double> &times)
{
	double times_summation = 0.0;	
	for (auto i = 0; i < times.size(); i++)
		times_summation += times[i];

	return times_summation;
}

double timesMean(const vector<double> &times)
{
	return timesSummation(times) / times.size();
}

double timesVariance(const vector<double> &times)
{
	double times_variance = 0.0;
	for(auto x : times)
		times_variance += (pow((x - timesMean(times)), 2)) / times.size();

	return times_variance;
}

double coefficientOfDetermination(const vector<double> &realTimes, const vector<double> &estimatedTimes)
{
	return timesVariance(estimatedTimes) / timesVariance(realTimes);
}

double fact(const double &n)
{
	return (n == 1 or n == 0) ? 1 : n * fact(n - 1);
}

/*---------------------
*	Estimated times:
---------------------*/
void calculateEstimatedTimesNlogN(const vector<double> &n, const vector<double> &a, vector<double> &estimatedTimes)
{
	for (auto i = 0; i < n.size(); i++)
		estimatedTimes.push_back(a[0] + (a[1] * n[i] * log(n[i])));
}

void calculateEstimatedTimeNlogN(const double &n, vector<double> &a)
{
	cout << (a[0] + a[1] * n * log(n)) * 1.00 * pow(10, -6) << " seconds." << endl;
	cout << (a[0] + a[1] * n * log(n)) * 1.6667 * pow(10, -8) << " minutes." << endl;
	cout << (a[0] + a[1] * n * log(n)) * 2.77778 * pow(10, -10) << " hours." << endl;
	cout << (a[0] + a[1] * n * log(n)) * 1.157407407407407 * pow(10, -11) << " days." << endl;
}

void calculateEstimatedTimesPolynomial(const vector<double> &n, const vector<double> &a, vector<double> &estimatedTimes)
{
	for (auto i = 0; i < n.size(); i++)
		estimatedTimes.push_back(a[0] + a[1] * n[i] + a[2] * pow(n[i], 2) + a[3] * pow(n[i], 3));
}

void calculateEstimatedTimePolynomial(const double &n, const vector<double> &a)
{
	cout << (a[0] + a[1] * n + a[2] * pow(n, 2) + a[3] * pow(n, 3)) * 1.00 * pow(10, -6) << " seconds." << endl;
	cout << (a[0] + a[1] * n + a[2] * pow(n, 2) + a[3] * pow(n, 3)) * 1.6667 * pow(10, -8) << " minutes." << endl;
	cout << (a[0] + a[1] * n + a[2] * pow(n, 2) + a[3] * pow(n, 3)) * 2.77778 * pow(10, -10) << " hours." << endl;
	cout << (a[0] + a[1] * n + a[2] * pow(n, 2) + a[3] * pow(n, 3)) * 1.157407407407407 * pow(10, -11) << " days." << endl;
}

void calculateEstimatedTimesFactorial(const vector<double> &n, const vector<double> &a, vector<double> &estimatedTimes)
{
	for (auto i = 0; i < n.size(); i++)
		estimatedTimes.push_back(a[0] + a[1] * fact(n[i]));
}

void calculateEstimatedTimeFactorial(const double &n, const vector<double> &a)
{
	cout << (a[0] + a[1] * fact(n)) * 1.00 * pow(10, -6) << " seconds." << endl;
	cout << (a[0] + a[1] * fact(n)) * 1.6667 * pow(10, -8) << " minutes." << endl;
	cout << (a[0] + a[1] * fact(n)) * 2.77778 * pow(10, -10) << " hours." << endl;
	cout << (a[0] + a[1] * fact(n)) * 1.157407407407407 * pow(10, -11) << " days." << endl;
}

/*---------------------
*	Adjustments:
---------------------*/
void NlogNAdjustment(const vector<double> &n, const vector<double> &realTimes, vector<double> &a)
{
	vector<double> NlogN;
	vector< vector<double> > A(2, vector<double>(2));
	vector< vector<double> > B(2, vector<double>(1));
	vector< vector<double> > X(2, vector<double>(1, 0));

	for (auto i = 0; i < n.size(); i++)
		NlogN.push_back(n[i] * log(n[i]));

	fillMatrixSystemEquations(A, B, NlogN, realTimes, 2);
	resolverSistemaEcuaciones(A, B, 2, X);

	for (auto i = 0; i < X.size(); i++)
		a[i] = X[i][0];

	cout << endl;
	for (auto i = 0; i < a.size(); i++)
		cout << "a[" << i << "] = " << a[i] << endl;

	cout << "t(n) = " << a[0] << " + " << a[1] << " n Log(n)" << endl;
}

void polynomialAdjustment(vector<double> &n, const vector<double> &realTimes, vector <double> &a)
{
	vector< vector<double> > A(4, vector<double>(4));
	vector< vector<double> > B(4, vector<double>(1));
	vector< vector<double> > X(4, vector<double>(1));

	fillMatrixSystemEquations(A, B, n, realTimes, 4);
	resolverSistemaEcuaciones(A, B, 4, X);

	for (auto i = 0; i < X.size(); i++)
		a[i] = X[i][0];

	cout << endl;
	for (auto i = 0; i < a.size(); i++)
		cout << "a[" << i << "] = " << a[i] << endl;

	cout << "t(n) = " << a[0] << " + " << a[1] << "n" << " + " << a[2] << "n²" << " + " << a[3] << "n³" << endl;
}

void factorialAdjustment(const vector<double> &n, const vector<double> &realTimes, vector <double> &a)
{
	vector<double> factorials;
	vector< vector<double> > A(2, vector<double>(2));
	vector< vector<double> > B(2, vector<double>(1));
	vector< vector<double> > X(2, vector<double>(1));

	for (auto i = 0; i < n.size(); i++)
		factorials.push_back(fact(n[i]));

	fillMatrixSystemEquations(A, B, factorials, realTimes, 2);
	resolverSistemaEcuaciones(A, B, 2, X);

	for (auto i = 0; i < X.size(); i++)
		a[i] = X[i][0];

	cout << endl;
	for (auto i = 0; i < a.size(); i++)
		cout << "a[" << i << "] = " << a[i] << endl;

	cout << "t(n) = " << a[0] << " + " << a[1] << "n!" << endl;
}