/*
*	File:	exponentiation.cpp
*	Author:	Ventura Lucena Martínez
*	Email:	i72lumav@uco.es
*/

#include "matrix.hpp"
#include "exponentiation.hpp"
#include "ClaseTiempo.cpp"

/*	Método 1:
Algoritmo Exponenciación(base, exponente;; resultado)
	inicio
		resultado <-- a

		para i de 1 a n - 1 hacer
			resultado <-- a * resultado
		fin para
	fin
*/

void method_1(const vector< vector<double> > &matrix, vector<double> &nElements, vector<double> &realTimes, const int &n, const int &exponent)
{
	Clock time;
	vector< vector<double> > aux(n, vector<double> (n));
	vector< vector<double> > result(n, vector<double> (n));

	copyMatrix(matrix, aux);

	time.start();
	if(exponent == 1)
		result = matrix;

	else
	{
		for (auto i = 1; i <= exponent - 1; i++)
		{
			multiplySquaredArrays(matrix, aux, result);
			//	Readjust memory address:
			aux = result;
		}
	}

	if(time.isStarted())
		time.stop();

	//printMatrix(result, n);
	realTimes.push_back(time.elapsed());

	cout << "Method 1: " << time.elapsed() << " microseconds." << endl;
}

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

void method_2(const vector< vector<double> > &matrix, vector<double> &nElements, vector<double> &realTimes, const int &n, const int &exponent)
{
	Clock time;
	vector< vector<double> > aux(n, vector<double> (n));
	vector< vector<double> > result(n, vector<double> (n));

	copyMatrix(matrix, aux);

	time.start();

	exponentiationDivideAndConquer(matrix, aux, result, exponent);
	//	Readjust memory address:
	aux = result;

	if(time.isStarted())
		time.stop();

	//printMatrix(result, n);
	realTimes.push_back(time.elapsed());

	cout << "Method 2: " << time.elapsed() << " microseconds." << endl;
}

/*	Método 3:
Algoritmo ExponenciaciónDyVIterativo(base, exponente;; r)
	inicio
		i <-- exponente
		x <-- base
		r <-- 1
		mientras i > 0 hacer
			si i mod 2 = 1 entonces i es impar
				r < -- rx
			finsi
			x <-- x²
			i <-- i / 2
		finmientras
	fin
*/

void method_3(const vector< vector<double> > &matrix, vector<double> &nElements, vector<double> &realTimes, const int &n, const int &exponent)
{
	Clock time;
	vector< vector<double> > aux(n, vector<double> (n));
	vector< vector<double> > result(n, vector<double> (n));

	autofillUnityMatrix(result, n);
	copyMatrix(matrix, aux);

	time.start();
		
	exponentiationDivideAndConquerIterative(aux, result, exponent);

	if(time.isStarted())
		time.stop();

	//printMatrix(result, n);
	realTimes.push_back(time.elapsed());

	cout << "Method 3: " << time.elapsed() << " microseconds." << endl;
}