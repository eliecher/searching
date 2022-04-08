#include "types.h"
#include <algorithm>

class undir_unwei_graph : public graph
{
#define VERTEXLIMIT 100
	// Maximum of 100 vertex numbered 0..99 are allowed
	vector<vector<bool>> adj;

public:
	undir_unwei_graph() : adj(vector<vector<bool>>(VERTEXLIMIT, vector<bool>(VERTEXLIMIT, false))) {}
	undir_unwei_graph(const vector<vector<int>> &edges) : adj(vector<vector<bool>>(VERTEXLIMIT, vector<bool>(VERTEXLIMIT, false)))
	{
		add_edges(edges);
	}
	void add_edges(const vector<vector<int>> &edges)
	{
		for (const vector<int> &e : edges)
			add_edge(e[0], e[1]);
	}
	virtual vector<pair<int, int>> get_adjacent(const int &node, const int &cost)
	{
		vector<pair<int, int>> res;
		int i = 0, c = cost + 1;
		for (const bool &b : adj[node])
		{
			if (b)
				res.push_back(make_pair(i, c));
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