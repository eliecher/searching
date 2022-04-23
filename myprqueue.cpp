#include <queue>
#include "types.h"

class myprqueue : public genopentype
{
	struct comparator
	{
		bool operator()(const search_node &s1, const search_node &s2)
		{
			return s1.c > s2.c;
		}
	};
	priority_queue<search_node, vector<search_node>, comparator> q;

public:
	void extract(int &node, int &cost, int &depth)
	{
		const search_node &p = q.top();
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