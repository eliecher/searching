#include "types.h"
void orderprinter(const vector<int> &order, ostream &out)
{
	int size = order.size();
	if (!size)
		return;
	out << order[0];
	for (int i = 1; i < size; i++)
		out << ", " << order[i];
}
void pathprinter(stack<int> &path, ostream &out)
{
	if (path.empty())
		return;
	out << path.top();
	path.pop();
	while (!path.empty())
	{
		out <<", "<< path.top();
		path.pop();
	}
}