/*
*	File:	traveling_salesman_greedy_algorithm.hpp
*	Author:	Ventura Lucena Martínez
*	Email:	i72lumav@uco.es
*/

#ifndef __TRAVELING_SALESMAN_GREEDY_ALGORITHM__
#define __TRAVELING_SALESMAN_GREEDY_ALGORITHM__

#include <stack>
#include <utility>
#include <valarray>

#include "graph.hpp"
#include "graph_utils.hpp"

template <class T> bool traveling_salesman_greedy(WGraph<T> &g, WGraph<T> &newGraph)
{
	for (size_t n = 0; n < g.size(); ++n)
		newGraph.add_node(g.node(n)->item());

	g.goto_first_node();
	for (auto i = 0; i < g.size() - 1; i++)
	{
		g.goto_first_edge();

		//typename WGraph<T>::NodeRef
		auto minimum_weight = g.current_edge();
		size_t u, v;
		while(g.has_current_edge()) 
		{
			if ((g.current_edge()->item() < minimum_weight->item()) and (!g.current_edge()->other(g.current_node())->is_visited())) 
			{
				u = g.current_edge()->first()->label();
				v = g.current_edge()->second()->label();
				minimum_weight = g.current_edge();
			}
			g.goto_next_edge();
		}

		newGraph.set_weight(newGraph.node(u), newGraph.node(v), minimum_weight->item());
		g.current_node()->set_visited(true);
		g.goto_node(minimum_weight->other(g.current_node()));
	}

	//typename WGraph<T>::NodeRef
	auto finalNode = newGraph.node(g.current_node()->label());
	//typename WGraph<T>::NodeRef
	auto firstNode = newGraph.node(0);
	//typename WGraph<T>::NodeRef
	auto finalEdgeWeight = g.weight(g.current_node(), g.node(0));

	newGraph.set_weight(finalNode, firstNode, finalEdgeWeight);

	return true;
}

#endif //__TRAVELING_SALESMAN_GREEDY_ALGORITHM__