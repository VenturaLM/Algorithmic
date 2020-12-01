/*
*	File:	main.cpp
*	Author:	Ventura Lucena Martínez
*	Email:	i72lumav@uco.es
*/
#include <ctime>

#include "n_queens_las_vegas.hpp"

int main()
{
	srand(time(NULL));

	nQueensLasVegas();

	return 0;
}