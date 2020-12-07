/*
*	File:	n_queens_las_vegas.cpp
*	Author:	Ventura Lucena Martínez
*	Email:	i72lumav@uco.es
*/

#include <iostream>

#include "n_queens_las_vegas.hpp"

bool isSafe(std::vector<int> &x, const int k)
{
	//	Tests if the current place is available.
	for (auto i = 1; i <= k - 1; i++)
	{
		if ( x[i] == x[k] or abs(x[i] - x[k]) == abs(i - k) )
			return false;
	}

	return true;
}

void printBoard(const std::vector<int> &x, const int nQueens)
{
	//	Store the solution in "board" array.
	std::vector< std::vector<int> > board(nQueens + 1, std::vector<int> (nQueens + 1));

	for (auto i = 1; i <= nQueens; i++)
	{
		for (auto j = 1; j <= nQueens; j++)
		{
			if (x[i] == j)
			{
				board[i][j] = 1;
				std::cout << "x ";
			}
			else
			{
				board[i][j] = 0;
				std::cout << "- ";
			}
		}
		std::cout << std::endl;
	}
}

void nQueensLasVegas(const int nQueens, std::vector<int> &x, bool &success)
{
	//	Initialize the solution at 0.
	std::vector<int> ok(nQueens + 1);
	int counter;

	//	All the "k - 1" queens. Searching all the possible positions for "k" queen.
	for (auto k = 1; k <= nQueens; k++)
	{
		counter = 0;
		//	Store all the possible solutions at "ok" vector.
		for (auto j = 1; j <= nQueens; j++)
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
		x[k] = ok[rand() % counter + 1];
	}

	if (counter == 0)
		success = false;
	else
		success = true;
}