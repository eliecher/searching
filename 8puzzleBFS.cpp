#include "types.h"
#include "tree.cpp"
#include "search.cpp"
#include "8puzzlegraph.cpp"
#include "myqueue.cpp"
#include <queue>

int main()
{
	_8puzzlegraph G;
	int start;
	cout << "Enter start vertex: ";
	cin >> start;
	_8puzzlegoaldecider g;
	tree t;
	vector<int> order;
	vector<pair<int, int>> res = search<myqueue>(G, start, order, t, g);
	cout << "ORDER (VISITED " << order.size() << " vertices):" << endl;
	// printorder(order);
	cout << endl;
	const int L = res.size();
	for (int i = 0; i < L; i++)
	{
		cout << "PATH " << i << "(cost " << res[i].second << "):" << endl;
		printpath(t.getpath(res[i].first));
	}
	return 0;
}