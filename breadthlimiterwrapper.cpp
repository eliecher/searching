#include "types.h"
#include <climits>
class breadthlimiterwrapper : public graph
{
	graph &G;
	int lim;

public:
	breadthlimiterwrapper(graph &G, int limit = INT_MAX) : G(G), lim(limit) {}
	int &limit() { return lim; }
	virtual vector<pair<int, int>> get_adjacent(const int &node, const int &cost)
	{
		vector<pair<int, int>> arr = G.get_adjacent(node, cost);
		if (arr.size() > lim)
			arr.resize(lim);
		return arr;
	}
};