/*
*	File:	main.cpp
*	Author:	Ventura Lucena Martínez
*	Email:	i72lumav@uco.es
*/

#include <ctime>
#include <iostream>

#include "n_queens_las_vegas.hpp"

bool nQueensLasVegasAlgorithm();

bool nQueensLasVegasAlgorithm()
{
	int nQueens;

	std::cout << "Queens = ";
	std::cin >> nQueens;
	std::cout << std::endl;

	//	There is no solution for 2 queens, nor for 3.
	//	Reference:
	//		[EN]	https://en.wikipedia.org/wiki/Eight_queens_puzzle#Counting_solutions
	if (nQueens == 2 or nQueens == 3)
	{
		std::cout << "Solution not found." << std::endl;
		return false;
	}

	std::vector<int> x(nQueens + 1, 0);

	bool success = false;
	int counter = 0;

	while (!success)
	{
		nQueensLasVegas(nQueens, x, success);
		counter++;
	}

	std::cout << "Solution found with " << counter << " attempts:" << std::endl;
	printBoard(x, nQueens);

	return true;
}

int main()
{
	srand(time(NULL));

	nQueensLasVegasAlgorithm();

	return 0;
}