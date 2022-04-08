#include "types.h"
#include "unweighted_undirected_graph/graph.cpp"

void init_graph(graph &g)
{
	undir_unwei_graph &G = *((undir_unwei_graph *)&g);
	cout << "Enter edges as u,v (no space)\n";
	cout << "To stop enter an edge of type i,i" << endl;
	int u, v;
	char comma;
	cin >> u >> comma >> v;
	while (u != v)
	{
		G.add_edge(u, v);
		cin >> u >> comma >> v;
	}
}