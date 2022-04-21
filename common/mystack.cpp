#include <stack>
#include "types.h"

class mystack : public genopentype
{
	stack<opennode> st;

public:
	opennode extract()
	{
		return st.top();
	}
	virtual void insert(const vector<opennode> &nodes)
	{
		int l = nodes.size();
		while (l--)
		{
			st.push(nodes[l]);
		}
	}
	bool unempty() { return !st.empty(); }
};