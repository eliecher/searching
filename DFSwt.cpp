#include "types.h"
#include "tree.cpp"
#include "search.cpp"
#include "simple_graph.cpp"
#include "mystack.cpp"
#include <queue>

int main()
{
	undir_unwei_graph G;
	int start;
	inputtaker(G);
	cout << "Enter start vertex: ";
	cin >> start;
	cout << "Enter number of goal vertices: ";
	int n, r;
	cin >> n;
	cout << "Enter " << n << " vertices: ";
	vector<int> arr;
	while (n--)
	{
		cin >> r;
		arr.push_back(r);
	}
	simple_goal_decider g(arr);
	tree t;
	vector<int> order;
	vector<pair<int, int>> res = search<mystack>(G, start, order, t, g);
	cout << "ORDER (VISITED " << order.size() << " vertices):" << endl;
	printsimpleorder(order);
	const int L = res.size();
	for (int i = 0; i < L; i++)
	{
		cout << "PATH " << i << "(cost " << res[i].second << "):" << endl;
		printsimplepath(t.getpath(res[i].first));
	}
	return 0;
}