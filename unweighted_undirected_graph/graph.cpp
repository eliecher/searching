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

void inputtaker(undir_unwei_graph &G)
{
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
void printsimplepath(stack<int> st)
{
	if (st.empty())
		cout << endl;
	cout << st.top();
	st.pop();
	while (!st.empty())
	{
		cout << "->" << st.top();
		st.pop();
	}
	cout << endl;
}