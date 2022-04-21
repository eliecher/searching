#include "types.h"
#include <climits>
class depthlimiterwrapper : public graph
{
	graph &G;
	int lim;
	unordered_map<VERTEX, int> vertex_depth_mapping;

public:
	depthlimiterwrapper(graph &G, int limit = INT_MAX) : G(G), lim(limit) {}
	int &limit() { return lim; }
	virtual vector<graph_node> get_adjacent(const solnode &s)
	{
		if (!vertex_depth_mapping.count(s.vertex))
			vertex_depth_mapping[s.vertex] = 0;
		int depth;
		if ((depth = vertex_depth_mapping[s.vertex]) >= lim)
			return {};
		vector<graph_node> arr = G.get_adjacent(s);
		depth++;
		for (graph_node &p : arr)
		{
			if (vertex_depth_mapping.count(p.s.vertex))
				continue;
			vertex_depth_mapping[p.s.vertex] = depth;
		}
		return arr;
	}
};