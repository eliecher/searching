#include "types.h"
#include <climits>
class depthlimiterwrapper : public graph
{
	graph &G;
	int lim;
	unordered_map<int, int> vertex_depth_mapping;

public:
	depthlimiterwrapper(graph &G, int limit = INT_MAX) : G(G), lim(limit) {}
	int &limit() { return lim; }
	virtual vector<pair<int, int>> get_adjacent(const int &node, const int &cost)
	{
		if (!vertex_depth_mapping.count(node))
			vertex_depth_mapping[node] = 0;
		int d;
		if ((d = vertex_depth_mapping[node]) >= lim)
			return {};
		vector<pair<int, int>> arr = G.get_adjacent(node, cost);
		d++;
		for (pair<int, int> &p : arr)
		{
			if (vertex_depth_mapping.count(p.first))
				continue;
			vertex_depth_mapping[p.first] = d;
		}
		return arr;
	}
};