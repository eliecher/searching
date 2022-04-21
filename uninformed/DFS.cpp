#include "types.h"
#include "common/search.cpp"
#include "common/mystack.cpp"
void search_and_print(graph &G, goaldecider &D, int start, int numsols = 1)
{
	vector<VERTEX> order;
	tree search_tree;
	vector<solnode> sols = search<mystack>(G, start, order, search_tree, D, numsols);
	cout << "ORDER (visited " << order.size() << " vertices):" << endl;
	orderprinter(order, cout);
	cout << endl;
	int count = 1;
	for (solnode &sol : sols)
	{
		cout << "PATH " << count++ << " (COST " << sol.cost << ")" << endl;
		stack<treenode> path = search_tree.getpath(sol.vertex);
		pathprinter(path, cout);
		cout << endl;
	}
}