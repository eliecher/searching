#include "types.h"
#include <climits>
class breadthlimiterwrapper : public graph
{
	graph &G;
	int lim;

public:
	breadthlimiterwrapper(graph &G, int limit = INT_MAX) : G(G), lim(limit) {}
	int &limit() { return lim; }
	virtual vector<graph_node> get_adjacent(const solnode &s)
	{
		vector<graph_node> arr = G.get_adjacent(s);
		if (arr.size() > lim)
			arr.resize(lim);
		return arr;
	}
};