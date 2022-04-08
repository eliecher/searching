#include "types.h"
#include <algorithm>


void inputtaker(undir_unwei_graph &G)
{
	cout << "Enter edges as u,v (no space)\n";
	cout << "To stop enter an edge of type i,i" << endl;
	int u, v;
	char comma;
	cin >> u >> comma >> v;
	while (u != v)
	{
		G.add_edge(u, v);
		cin >> u >> comma >> v;
	}
}

class simple_goal_decider : public goaldecider
{
	vector<int> candidates;

public:
	simple_goal_decider(const vector<int> &candidates) : candidates(candidates)
	{
		sort(this->candidates.begin(), this->candidates.end());
	}
	bool operator()(const int &n)
	{
		int l = 0, u = candidates.size() - 1;
		while (l <= u)
		{
			int m = l + u >> 1;
			if (candidates[m] == n)
				return true;
			else if (candidates[m] > n)
				u = m - 1;
			else
				l = m + 1;
		}
		return false;
	}
};
void printsimpleorder(vector<int> order)
{
	if (order.empty())
		cout << endl;
	const int L = order.size();
	cout << order[0];
	for (int i = 1; i < L; i++)
		cout << ',' << order[i];
	cout << endl;
}
void printsimplepath(stack<int> st)
{
	if (st.empty())
		cout << endl;
	cout << st.top();
	st.pop();
	while (!st.empty())
	{
		cout << "->" << st.top();
		st.pop();
	}
	cout << endl;
}