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
	void insert(const int &node, const int &cost, const int &depth)
	{
		q.push(search_node(node, cost, depth));
	}
	bool unempty() { return !q.empty(); }
};