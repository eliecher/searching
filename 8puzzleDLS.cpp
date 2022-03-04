#include "types.h"
#include "search.cpp"
#include "8puzzlegraph.cpp"
#include "mystack.cpp"
#include "depthlimiterwrapper.cpp"
#include <queue>

int main()
{
	_8puzzlegraph G;
	int start;
	cout << "Enter start vertex: ";
	cin >> start;
	cout << "Enter depth limit: ";
	int lim;
	cin >> lim;
	_8puzzlegoaldecider g;
	tree t;
	vector<int> order;
	depthlimiterwrapper GG(G, lim);
	vector<pair<int, int>> res = search<mystack>(GG, start, order, t, g);
	cout << "ORDER:" << endl;
	printorder(order);
	cout << endl;
	const int L = res.size();
	for (int i = 0; i < L; i++)
	{
		cout << "PATH " << i << "(cost " << res[i].second << "):" << endl;
		printpath(t.getpath(res[i].first));
	}
	return 0;
}