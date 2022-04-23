#include "types.h"
#include <queue>

template <class h>
class mygreedyBFSqueue : public genopentype
{
	template <class T>
	struct comparator
	{
		T heu;
		bool operator()(const search_node &s1, const search_node &s2)
		{
			return heu(s1.v) > heu(s2.v);
		}
	};
	priority_queue<search_node, vector<search_node>, comparator<h>> q;

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
		// cout << "inserted " << node << " top " << q.top().v << " heu " << h()(q.top().v) << endl;
	}
	bool unempty() { return !q.empty(); }
};