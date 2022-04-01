

#include "types.h"
#include "climits"

template <typename op>
vector<pair<int, int>> search(graph &G, const int &start, vector<int> &order, tree &search_tree, goaldecider &goalchecker, int numsols = 1)
{
	vector<pair<int, int>> solutions;
	op open;
	search_tree[start] = INT_MIN;
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
		vector<pair<int, int>> neigh = G.get_adjacent(node, cost),filtered;
		++depth;
		for (pair<int, int> &nd : neigh)
		{
			if (closed.count(nd.first))
				continue;
			closed.insert(nd.first);
			filtered.push_back(nd);
			search_tree[nd.first] = node;
		}
		open.insert(filtered,depth);
	}
	return solutions;
}