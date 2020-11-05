/*
*	File:	determinants.hpp
*	Author:	Ventura Lucena Martínez
*	Email:	i72lumav@uco.es
*/

#ifndef DETERMINANTS_HPP
#define DETERMINANTS_HPP

using namespace std;

#include <vector>
#include <iostream>

/*---------------------
*	Matrix operations:
---------------------*/
void autofillMatrix(vector< vector<double> > &matrix, const int &order);
void printMatrix(const vector< vector<double> > &matrix, const int &order);
double calculateIterativeDeterminant(vector< vector<double> > &matrix, const double &n);
double calculateRecursiveDeterminant(vector< vector<double> > &matrix, const double &n);
void getMatrixCofactor(vector< vector<double> > &matrix, vector< vector<double> > &aux, int p, int q, int n);

/*---------------------
*	Determinants:
---------------------*/
void iterativeDeterminant();
void recursiveDeterminant();

#endif