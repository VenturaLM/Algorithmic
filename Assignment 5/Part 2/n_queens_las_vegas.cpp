/*
*	File:	n_queens_las_vegas.cpp
*	Author:	Ventura Lucena Martínez
*	Email:	i72lumav@uco.es
*/

#include <iostream>

#include "n_queens_las_vegas.hpp"

#define N 8

bool isSafe(std::vector<int> &x, int k)
{
	for (auto i = 0; i < N; i++)
	{
		if ( x[i] == x[k] or abs(x[i] - x[k]) == abs(i - k) )
			return false;
	}

	return true;
}

bool nQueensLasVegas()
{
	//	Initialize the solution at 0.
	std::vector<int> x(N, 0);
	std::vector<int> ok(N);
	unsigned int counter = 0;

	//	All the "k - 1" queens. Searching all the possible positions for "k" queen.
	for (auto k = 0; k < N; k++)
	{

		//	Store all the possible solutions at "ok" vector.
		for (auto j = 0; j < N; j++)
		{
			x[k] = j;
			if (isSafe(x, k))
			{
				//	It is possible to place the queen on the column "j".
				counter++;
				ok[counter] = j;
			}
		}

		//	Possition for queen "k" not found.
		if (counter == 0)
			break;

		//	It is possible to place the queen k and it selects a ramdon position.
		x[k] = ok[rand() % counter];
	}

	if (counter == 0)
		return false;
	else
		return true;
}