/*
*	File:	other_graph_utils.hpp
*	Author:	Ventura Lucena Martínez
*	Email:	i72lumav@uco.es
*/

#ifndef __OTHER_GRAPH_UTILS_HPP__
#define __OTHER_GRAPH_UTILS_HPP__

template<class T>
void savePaths(std::vector<float> &path_weight, std::vector< std::vector <size_t> > &allPaths, WGraph<T> &g)
{
	for(unsigned int i = 0; i < allPaths.size(); i++)
	{
		std::cout << "Path [" << i << "]: ";
		for(unsigned int j = 0; j <= g.capacity() - 1; j++)
		{
			std::cout << allPaths[i][j] << ", ";
			//	Compute every path weight.
			path_weight[i] += g.weight( g.node(allPaths[i][j]), g.node(allPaths[i][j + 1]) );
		}

		//	Prints every weight, exposing at the right side the previous weight computed.
		std::cout  	<< allPaths[i][g.capacity()] 
					<< " → Weight = " << path_weight[i] 
					<< std::endl;
	}
}

float computeMinimunPath(const std::vector<float> path_weight, int &index)
{
	auto minimum = path_weight[0];
	for(auto i = 1; i < path_weight.size(); i++)
	{
		if(path_weight[i] < minimum)
		{
			minimum = path_weight[i];
			index = i;
		}
	}

	return minimum;
}

template<class T>
void printIdealPath(const std::vector<float> path_weight, const std::vector< std::vector <size_t> > allPaths, WGraph<T> &g, const int index)
{
	//  Prints the ideal path with city id.
	std::cout   << "\nIdeal Path [" 
				<< index 
				<< "]:\n\n\t";
	for(unsigned int j = 0; j <= g.capacity() - 1; j++)
		std::cout << allPaths[index][j] << ", ";
	std::cout   << allPaths[index][g.capacity()]
				<< " → Weight = " << path_weight[index]
				<< std::endl;

	//	Prints the ideal path - (City name, City u - City v weight).
	std::cout <<"\t";
	for(unsigned int j = 0; j <= g.capacity() - 1; j++)
		std::cout   << g.node(allPaths[index][j])->item().name
					<<  " - (" << g.weight( g.node(allPaths[index][j]), g.node(allPaths[index][j+1]) ) << ") - ";
	std::cout << g.node( allPaths[index][g.capacity()] )->item().name << std::endl;
	std::cout << std::endl;
}

#endif