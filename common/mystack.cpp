#include <stack>
#include "types.h"

class mystack : public genopentype
{
	stack<search_node> st;

public:
	void extract(int &node, int &cost, int &depth)
	{
		search_node &p = st.top();
		node = p.v;
		cost = p.c;
		depth = p.d;
		st.pop();
	}
	virtual void insert(const vector<pair<int, int>> &nodes, const int &depth)
	{
		int l = nodes.size();
		vector<pair<int, int>>::const_reverse_iterator it = nodes.rbegin();
		while (l--)
		{
			st.push(search_node(it->first, it->second, depth));
			it++;
		}
	}
	virtual void insert(const vector<pair<int, int>> &nodes, const vector<int> &depth)
	{
		if (nodes.size() != depth.size())
			throw myexcep("depth and nodes mismatch lengths");
		vector<int>::const_reverse_iterator d = depth.rbegin();
		int l = nodes.size();
		vector<pair<int, int>>::const_reverse_iterator it = nodes.rbegin();
		while (l--)
		{
			st.push(search_node(it->first, it->second, *d));
			it++;
			d++;
		}
	}
	bool unempty() { return !st.empty(); }
};