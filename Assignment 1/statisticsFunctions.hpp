/*
*	File:	statisticsFunctions.hpp
*	Author:	Ventura Lucena Martínez
*	Email:	i72lumav@uco.es
*/

#ifndef STATISTICSFUNCTIONS_HPP
#define STATISTICSFUNCTIONS_HPP

#include <vector>

using namespace std;

/*---------------------
*	Operations:
---------------------*/
double summation(vector<double> &n, const vector<double> &t, int expN, int expT);
void fillMatrixSystemEquations(vector< vector<double> > &A, vector< vector<double> > &B, vector<double> &n, const vector<double> &realTimes, int orden);
double timesSummation(const vector<double> &times);
double timesMean(const vector<double> &times);
double timesVariance(const vector<double> &times);
double coefficientOfDetermination(const vector<double> &realTimes, const vector<double> &estimatedTimes);
double fact(const double &n);

/*---------------------
*	Estimated times:
---------------------*/
void calculateEstimatedTimesNlogN(const vector<double> &n, const vector<double> &a, vector<double> &estimatedTimes);
void calculateEstimatedTimeNlogN(const double &n, vector<double> &a);
void calculateEstimatedTimesPolynomial(const vector<double> &n, const vector<double> &a, vector<double> &estimatedTimes);
void calculateEstimatedTimePolynomial(const double &n, const vector<double> &a);
void calculateEstimatedTimesFactorial(const vector<double> &n, const vector<double> &a, vector<double> &estimatedTimes);
void calculateEstimatedTimeFactorial(const double &n, const vector<double> &a);

/*---------------------
*	Adjustments:
---------------------*/
void NlogNAdjustment(const vector<double> &n, const vector<double> &realTimes, vector<double> &a);
void polynomialAdjustment(vector<double> &n, const vector<double> &realTimes, vector <double> &a);
void factorialAdjustment(const vector<double> &n, const vector<double> &realTimes, vector <double> &a);

#endif