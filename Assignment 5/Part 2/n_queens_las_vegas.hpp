/*
*	File:	n_queens_las_vegas.hpp
*	Author:	Ventura Lucena Martínez
*	Email:	i72lumav@uco.es
*/

#ifndef __N_QUEENS_LAS_VEGAS__
#define __N_QUEENS_LAS_VEGAS__

#include <vector>
#include <cstdlib>

bool nQueensLasVegas();
bool isSafe(std::vector<int> &x, int k);

#endif