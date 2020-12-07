/*
*	File:	n_queens_las_vegas.hpp
*	Author:	Ventura Lucena Martínez
*	Email:	i72lumav@uco.es
*/

#ifndef __N_QUEENS_LAS_VEGAS__
#define __N_QUEENS_LAS_VEGAS__

#include <vector>
#include <cstdlib>

bool isSafe(std::vector<int> &x, const int k);
void printBoard(const std::vector<int> &x, const int nQueens);
void nQueensLasVegas(const int nQueens, std::vector<int> &x, bool &success);

#endif