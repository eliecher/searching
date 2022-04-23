#include "types.h"
#include <climits>

int &tree::operator[](const int &n)
{
	return table[n];
}

bool tree::is_in(const int &n)
{
	return table.find(n) != table.end();
}

tree::tree()
{
	table.clear();
}

stack<pair<int, int>> tree::getpath(const int &n)
{
	stack<pair<int, int>> s;
	int c = n;
	while (c != INT_MIN)
	{
		s.push(make_pair(op(c), c));
		c = table[c];
	}
	return s;
}
int &tree::op(const int &n)
{
	return optable[n];
}