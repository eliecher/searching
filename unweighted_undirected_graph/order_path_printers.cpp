#include "types.h"
void orderprinter(const vector<VERTEX> &order, ostream &out)
{
	int size = order.size();
	if (!size)
		return;
	out << order[0];
	for (int i = 1; i < size; i++)
		out << ", " << order[i];
}
void pathprinter(stack<treenode> &path, ostream &out)
{
	if (path.empty())
		return;
	out << path.top().parent;
	path.pop();
	while (!path.empty())
	{
		out <<", "<< path.top().parent;
		path.pop();
	}
}