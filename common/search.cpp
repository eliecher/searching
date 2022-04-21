

#include "types.h"
#include "climits"

template <typename op>
vector<solnode> search(graph &G, const VERTEX &start, vector<VERTEX> &order, tree &search_tree, goaldecider &goalchecker, int numsols = 1)
{
	vector<solnode> solutions;
	op open;
	search_tree[start] = treenode();
	open.insert({opennode(solnode(start, 0), 0)});
	unordered_set<VERTEX> closed;
	closed.insert(start);
	while (open.unempty() && numsols)
	{
		opennode cur = open.extract();
		solnode &s = cur.s;
		int depth = cur.depth;
		order.push_back(cur.s.vertex);
		if (goalchecker(cur.s.vertex))
		{
			numsols--;
			solutions.push_back(s);
		}
		vector<graph_node> neigh = G.get_adjacent(s);
		vector<opennode> filtered;
		++depth;
		for (graph_node &nd : neigh)
		{
			if (closed.count(nd.s.vertex))
				continue;
			closed.insert(nd.s.vertex);
			filtered.push_back(opennode(nd.s, depth));
			search_tree[nd.s.vertex] = treenode(s.vertex, nd.operation);
		}
		open.insert(filtered);
	}
	return solutions;
}