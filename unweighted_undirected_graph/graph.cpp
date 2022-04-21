#include "types.h"
#include <algorithm>

class undir_unwei_graph : public graph
{
#define VERTEXLIMIT 100
	// Maximum of 100 vertex numbered 0..99 are allowed
	vector<vector<bool>> adj;

public:
	undir_unwei_graph() : adj(vector<vector<bool>>(VERTEXLIMIT, vector<bool>(VERTEXLIMIT, false)))
	{
		operation_names[1] = "";
	}
	undir_unwei_graph(const vector<vector<int>> &edges) : adj(vector<vector<bool>>(VERTEXLIMIT, vector<bool>(VERTEXLIMIT, false)))
	{
		add_edges(edges);
	}
	void add_edges(const vector<vector<int>> &edges)
	{
		for (const vector<int> &e : edges)
			add_edge(e[0], e[1]);
	}
	virtual vector<graph_node> get_adjacent(const solnode &s)
	{
		vector<graph_node> res;
		int i = 0, c = s.cost + 1;
		for (const bool &b : adj[s.vertex])
		{
			if (b)
				res.push_back(graph_node(solnode(b, c), 1));
			i++;
		}
		return res;
	}
	inline void add_edge(const int &u, const int &v)
	{
		adj[u][v] = adj[v][u] = true;
	}
};

graph &get_graph()
{
	return *(new undir_unwei_graph());
}
void destroy_graph(graph &g)
{
	delete (undir_unwei_graph *)&g;
}

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