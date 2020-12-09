/*
*	File:	traveling_salesman_backtracking_algorithm.hpp
*	Author:	Ventura Lucena Martínez
*	Email:	i72lumav@uco.es
*/

#ifndef __TRAVELLING_SALESMAN_BACKTRACKING_ALGORITHM_HPP__
#define __TRAVELLING_SALESMAN_BACKTRACKING_ALGORITHM_HPP__

#include <stack>
#include <utility>
#include <valarray>

#include "graph.hpp"
#include "graph_utils.hpp"
#include "other_graph_utils.hpp"

/**
 * @brief Create a new graph from the old graph by selecting the edges whose weight is greter than 200.
 * @arg[in] g is a weighted graph.
 * @arg[out] newGraph is the new graph.
 * @pre the weigths meet the triangular inequality: d(u,v) <= d(u,k) + d(k,v) for all u!=v!=k.
 */
template <class T>
bool
traveling_salesman_dynamic(WGraph<T> & g, float threshold)
{
	//This algorithm travel the graph from the first node
	//std::vector< typename WGraph<T>::EdgeRef > edges;
	std::vector<bool> visited(g.capacity()); //This vector is used to check if the node has been visited.
	std::vector<size_t> currentPath;
	std::vector< std::vector <size_t> > allPaths;

	for(size_t i = 0; i < g.capacity(); i++) //All the nodes are marked as not visited
		visited[i] = false; 

	//	Number of prunings carried out.
	int nPrunings = 0;
	g.goto_first_node();

	deep_travel(g, g.current_node()->item(), visited, currentPath, allPaths, threshold, nPrunings);

	//	We store every path weight in the "path_weight" vector.
	std::vector<float> path_weight(allPaths.size(), 0);
	savePaths(path_weight, allPaths, g);

	//	Compute the minimun path among all the paths.
	int index = 0;
	float minimum = computeMinimunPath(path_weight, index);

	printIdealPath(path_weight, allPaths, g, index);
	std::cout << nPrunings << " prunings carried out.\n" << std::endl;

	return true;
}

template <class T>
void
deep_travel(WGraph<T> &g, const T keyNode, std::vector<bool> visited, std::vector<size_t> currentPath, std::vector< std::vector <size_t> > &allPaths, float &threshold, int &nPrunings) 
{
	typename WGraph<T>::NodeRef u, v;
	typename WGraph<T>::EdgeRef e;
	
	u = g.find(keyNode); //KeyNode is searched in the graph
	visited[u->label()] = true; //The current node is marked as visited

	currentPath.push_back(u->label());

	//	The current node is added to current path.
	float current_weight = 0.0;
	bool flag = true;

	if (currentPath.size() > 1)
	{
		if (currentPath.size() == g.capacity())
		{
			//	Joins the last node with the first one.
			currentPath.push_back(currentPath[0]);
		}

		for (auto i = 0; i <= currentPath.size() - 2; i++)
			current_weight += g.weight( g.node(currentPath[i]), g.node(currentPath[i + 1]) );

		if (current_weight > threshold){
			//	If the threshold is overpassed, then the path is not added.
			flag = false;
			nPrunings++;
			currentPath.pop_back();
			return;
		}
	}

	//A new path has been found.
	if (currentPath.size() == g.capacity() + 1 and flag == true and current_weight < threshold)
	{
		current_weight = 0.0;

		for (auto i = 0; i <= currentPath.size() - 2; i++)
			current_weight += g.weight( g.node(currentPath[i]), g.node(currentPath[i + 1]) );

		//	Updates the threshold.
		if(current_weight < threshold)
			threshold = current_weight;

		//The new path is saved in allPath.
		allPaths.push_back(currentPath);
	}
		
	g.goto_first_edge();
	while (g.has_current_edge())
	{
		e = g.current_edge();
		v = e->other(u);
		if (not visited[v->label()])
		{
			deep_travel(g, v->item(), visited, currentPath, allPaths, threshold, nPrunings);
			g.goto_edge(u, v); //It is necessary for dont lose the current edge when all the recursive calls end.
		}
		g.goto_next_edge(); //Go te the next edge
	}
}

#endif //__TRAVELLING_SALESMAN_DYNAMIC_ALGORITHM_HPP__