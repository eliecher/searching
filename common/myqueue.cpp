#include <queue>
#include "types.h"

class myqueue : public genopentype
{
	queue<search_node> q;

public:
	void extract(int &node, int &cost, int &depth)
	{
		search_node &p = q.front();
		node = p.v;
		cost = p.c;
		depth = p.d;
		q.pop();
	}
	virtual void insert(const vector<pair<int, int>> &nodes, const int &depth)
	{
		for (const pair<int, int> &node : nodes)
			q.push(search_node(node.first, node.second, depth));
	}
	virtual void insert(const vector<pair<int, int>> &nodes, const vector<int> &depth)
	{
		if (nodes.size() != depth.size())
			throw myexcep("depth and nodes mismatch lengths");
		vector<int>::const_iterator d = depth.begin();
		for (const pair<int, int> &node : nodes)
			q.push(search_node(node.first, node.second, *(d++)));
	}
	bool unempty() { return !q.empty(); }
};