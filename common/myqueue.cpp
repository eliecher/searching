#include <queue>
#include "types.h"

class myqueue : public genopentype
{
	queue<opennode> q;

public:
	opennode extract()
	{
		return q.front();
	}
	virtual void insert(const vector<opennode> &nodes)
	{
		for (const opennode &o : nodes)
			q.push(o);
	}
	bool unempty() { return !q.empty(); }
};