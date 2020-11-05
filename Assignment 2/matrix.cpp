/*
*	File:	matrix.cpp
*	Author:	Ventura Lucena Martínez
*	Email:	i72lumav@uco.es
*/

#include <vector>

#include "matrix.hpp"

using namespace std;

/*---------------------
*	Matrix operations:
---------------------*/
void autofillMatrix(vector< vector<double> > &matrix, const int &order)
{
	for (auto i = 0; i < order; i++)
	{
		for (auto j = 0; j < order; j++)
			matrix[i][j] = rand() / (RAND_MAX / 3.00);
	}
}

void autofillUnityMatrix(vector< vector<double> > &matrix, const int &order)
{
	for (auto i = 0; i < matrix.size(); i++)
		matrix[i][i] = 1;
}

void printMatrix(const vector< vector<double> > &matrix, const int &order)
{
	cout << endl;
	for (auto i = 0; i < order; i++)
	{
		for (auto j = 0; j < order; j++)
			cout << "[" << matrix[i][j] << "]\t\t";

		cout << endl;
	}
}

void multiplySquaredArrays(const vector< vector<double> > &matrix_1, const vector< vector<double> > &matrix_2, vector< vector<double> > &result)
{
	for(auto i = 0; i < matrix_1.size(); i++)
	{
		for(auto j = 0; j < matrix_2[0].size(); j++)
		{
			result[i][j] = 0.0;
			for(auto k = 0; k < matrix_1[0].size(); k++)
				result[i][j] = result[i][j] + matrix_1[i][k] * matrix_2[k][j];
		}
	}
}

vector< vector<double> > multiplySquaredArrays(const vector< vector<double> > &matrix_1, const vector< vector<double> > &matrix_2, const int &order)
{
	vector< vector<double> > result(order, vector<double> (order, 0.0));

	for(auto i = 0; i < order; i++)
	{
		for(auto j = 0; j < order; j++)
		{
			for(auto k = 0; k < order; k++)
				result[i][j] = result[i][j] + matrix_1[i][k] * matrix_2[k][j];
		}
	}
	return result;
}

void copyMatrix(const vector< vector<double> > &matrix_1, vector< vector<double> > &matrix_2)
{
	for (auto i = 0; i < matrix_1.size(); i++)
	{
		for (auto j = 0; j < matrix_1.size(); j++)
			matrix_2[i][j] = matrix_1[i][j];
	}
}

/*--------------------------
*	Matrix exponentiation:
--------------------------*/

/*	Método 2:
Algoritmo ExponenciaciónDyV(base, exponente;;)
	inicio
		si exponente = 1 entonces
			devolver base
		sino
			si exponente mod 2 = 0 entonces exponente no es par
				aux <--ExponenciacionDyV(base, exponente / 2)
				devolver aux * aux
			sino
				devolver a * ExponenciacionDyV(base, exponente - 1)
			finsi
		finsi
	fin
*/

vector< vector<double> > exponentiationDivideAndConquer(const vector< vector<double> > &matrix, vector< vector<double> > &aux, vector< vector<double> > &result, const int &exponent)
{
	if(exponent == 1)
	{
		return matrix;
	}
	else
	{
		if(exponent % 2 == 0)
		{
			aux = exponentiationDivideAndConquer(matrix, aux, result, exponent / 2);
			multiplySquaredArrays(aux, aux, result);
			return result;
		}else
			multiplySquaredArrays(matrix, exponentiationDivideAndConquer(matrix, aux, result, exponent - 1), result);
			return result;
	}
}

/*	Método 3:
Algoritmo ExponenciaciónDyVIterativo(base, exponente;; r)
	inicio
		i <-- exponente
		x <-- base (matrix)
		r <-- 1 (result)
		mientras i > 0 hacer
			si i mod 2 = 1 entonces i es impar
				r < -- rx
			finsi
			x <-- x²
			i <-- i / 2
		finmientras
	fin
*/

void exponentiationDivideAndConquerIterative(vector< vector<double> > &aux, vector< vector<double> > &result, const int &exponent)
{
	int i = exponent;

	while(i > 0)
	{
		if(i % 2 == 1)
			result = multiplySquaredArrays(result, aux, result.size());
		
		aux = multiplySquaredArrays(aux, aux, aux.size());
		i = i / 2;
	}
}