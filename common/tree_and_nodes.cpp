#include "types.h"
#include <climits>

treenode::treenode(const VERTEX &parent , const int &operation) : parent(parent), operation(operation) {}

opennode::opennode(const solnode &s, const int &depth ) : s(s), depth(depth) {}

solnode::solnode(const VERTEX &vertex, const COST &cost ) : vertex(vertex), cost(cost) {}

graph_node::graph_node(const solnode &s, const int &operation) : operation(operation), s(s) {}

treenode &tree::operator[](const VERTEX &n)
{
	return table[n];
}

bool tree::is_in(const VERTEX &n)
{
	return table.find(n) != table.end();
}

tree::tree()
{
	table.clear();
}

stack<treenode> tree::getpath(const VERTEX &n)
{
	stack<treenode> s;
	treenode t;
	VERTEX c = n;
	while (c != VERTEX_MIN)
	{
		t = table[c];
		s.push(treenode(c, t.operation));
		c = t.parent;
	}
	return s;
}