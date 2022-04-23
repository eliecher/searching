#include "types.h"
#include <algorithm>
unordered_map<int, string> opnamemapping;
class undir_wei_graph : public graph
{
#define VERTEXLIMIT 100
	// Maximum of 100 vertex numbered 0..99 are allowed
	vector<vector<int>> adj;

public:
	undir_wei_graph() : adj(vector<vector<int>>(VERTEXLIMIT, vector<int>(VERTEXLIMIT, INT32_MAX)))
	{
		for (int i = 0; i < VERTEXLIMIT; i++)
			adj[i][i] = 0;
		opnamemapping[0] = "START AT ";
		opnamemapping[1] = " -> ";
	}
	undir_wei_graph(const vector<vector<int>> &edges) : adj(vector<vector<int>>(VERTEXLIMIT, vector<int>(VERTEXLIMIT, INT32_MAX)))
	{
		for (int i = 0; i < VERTEXLIMIT; i++)
			adj[i][i] = 0;
		opnamemapping[0] = "START -> ";
		opnamemapping[1] = " -> ";
		add_edges(edges);
	}
	void add_edges(const vector<vector<int>> &edges)
	{
		for (const vector<int> &e : edges)
			add_edge(e[0], e[1], e[2]);
	}
	virtual vector<pair<pair<int, int>, int>> get_adjacent(const int &node, const int &cost)
	{
		vector<pair<pair<int, int>, int>> res;
		int i = 0;
		for (const int &w : adj[node])
		{
			if (w != INT32_MAX)
				res.push_back(make_pair(make_pair(i, w + cost), 1));
			i++;
		}
		return res;
	}
	inline void add_edge(const int &u, const int &v, const int &w)
	{
		adj[u][v] = adj[v][u] = w;
		// cout << "adding edge wt " << w << " bw " << u << ", " << v << endl;
	}
};

void inputtaker(undir_wei_graph &G)
{
	cout << "Enter edges as u,v,wt (no space)\n";
	cout << "To stop enter an edge of type i,i,wt" << endl;
	int u, v, w;
	char comma;
	cin >> u >> comma >> v >> comma >> w;
	while (u != v)
	{
		G.add_edge(u, v, w);
		cin >> u >> comma >> v >> comma >> w;
	}
}

class simple_goal_decider : public goaldecider
{
	vector<int> candidates;

public:
	simple_goal_decider(const vector<int> &candidates) : candidates(candidates)
	{
		sort(this->candidates.begin(), this->candidates.end());
	}
	bool operator()(const int &n)
	{
		int l = 0, u = candidates.size() - 1;
		while (l <= u)
		{
			int m = l + u >> 1;
			if (candidates[m] == n)
				return true;
			else if (candidates[m] > n)
				u = m - 1;
			else
				l = m + 1;
		}
		return false;
	}
};
void printsimpleorder(vector<int> order)
{
	if (order.empty())
		cout << endl;
	const int L = order.size();
	cout << order[0];
	for (int i = 1; i < L; i++)
		cout << ',' << order[i];
	cout << endl;
}
void printsimplepath(stack<pair<int, int>> st)
{
	if (st.empty())
		cout << endl;
	while (!st.empty())
	{
		cout << opnamemapping[st.top().first] << st.top().second;
		st.pop();
	}
	cout << endl;
}