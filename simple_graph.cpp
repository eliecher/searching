#include "types.h"
#include <algorithm>
unordered_map<int, string> opnamemapping;
class undir_unwei_graph : public graph
{
#define VERTEXLIMIT 100
	// Maximum of 100 vertex numbered 0..99 are allowed
	vector<vector<bool>> adj;

public:
	undir_unwei_graph() : adj(vector<vector<bool>>(VERTEXLIMIT, vector<bool>(VERTEXLIMIT, false)))
	{
		opnamemapping.clear();
		opnamemapping[1] = " -> ";
		opnamemapping[0] = "START AT ";
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
	virtual vector<pair<pair<int, int>, int>> get_adjacent(const int &node, const int &cost)
	{
		vector<pair<pair<int, int>, int>> res;
		int i = 0, c = cost + 1;
		for (const bool &b : adj[node])
		{
			if (b)
				res.push_back(make_pair(make_pair(i, c), 1));
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

class static_defined_heuristic
{
	unordered_map<int, int> h;
#define H(A, B) h[A] = B;

public:
	static_defined_heuristic()
	{
		H(1, 6)
		H(2, 2)
		H(3, 3)
		H(4, 2)
		H(5, 4)
		H(6, 2)
		H(7, 0)
		H(8, 1)
		H(9, 1)
		H(10, 1)
	}
	int operator()(const int &n)
	{
		return h[n];
	}
};