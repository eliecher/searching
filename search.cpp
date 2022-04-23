

#include "types.h"
#include "climits"

template <typename op>
vector<pair<int, int>> search(graph &G, const int &start, vector<int> &order, tree &search_tree, goaldecider &goalchecker, int numsols = 1)
{
	vector<pair<int, int>> solutions;
	op open;
	search_tree[start] = INT_MIN;
	search_tree.op(start) = 0;
	open.insert(start, 0, 0);
	unordered_set<int> closed;
	closed.insert(start);
	while (open.unempty() && numsols)
	{
		int node, cost, depth;
		open.extract(node, cost, depth);
		order.push_back(node);
		if (goalchecker(node))
		{
			numsols--;
			solutions.push_back(make_pair(node, cost));
		}
		vector<pair<pair<int, int>, int>> neigh = G.get_adjacent(node, cost);
		++depth;
		for (pair<pair<int, int>, int> &adj : neigh)
		{
			pair<int, int> &nd = adj.first;
			if (closed.count(nd.first))
				continue;
			closed.insert(nd.first);
			open.insert(nd.first, nd.second, depth);
			search_tree[nd.first] = node;
			search_tree.op(nd.first) = adj.second;
		}
	}
	return solutions;
}