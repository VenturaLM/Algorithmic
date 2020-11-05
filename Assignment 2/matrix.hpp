/*
*	File:	matrix.hpp
*	Author:	Ventura Lucena Martínez
*	Email:	i72lumav@uco.es
*/

#ifndef MATRIX_HPP
#define MATRIX_HPP

using namespace std;

#include <vector>
#include <iostream>

/*---------------------
*	Matrix operations:
---------------------*/
void autofillMatrix(vector< vector<double> > &matrix, const int &order);
void autofillUnityMatrix(vector< vector<double> > &matrix, const int &order);
void printMatrix(const vector< vector<double> > &matrix, const int &order);
void multiplySquaredArrays(const vector< vector<double> > &matrix_1, const vector< vector<double> > &matrix_2, vector< vector<double> > &result);
vector< vector<double> > multiplySquaredArrays(const vector< vector<double> > &matrix_1, const vector< vector<double> > &matrix_2, const int &order);
void copyMatrix(const vector< vector<double> > &matrix_1, vector< vector<double> > &matrix_2);
vector< vector<double> > exponentiationDivideAndConquer(const vector< vector<double> > &matrix, vector< vector<double> > &aux, vector< vector<double> > &result, const int &exponent);
void exponentiationDivideAndConquerIterative(vector< vector<double> > &aux, vector< vector<double> > &result, const int &exponent);

#endif