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

stack<int> tree::getpath(const int &n)
{
	stack<int> s;
	int c = n;
	while (c != INT_MIN)
	{
		s.push(c);
		c = table[c];
	}
	return s;
}