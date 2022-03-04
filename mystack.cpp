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
	void insert(const int &node, const int &cost, const int &depth)
	{
		st.push(search_node(node, cost, depth));
	}
	bool unempty() { return !st.empty(); }
};