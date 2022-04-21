#include "types.h"
#include <algorithm>

class simple_goal_decider : public goaldecider
{
	vector<VERTEX> candidates;

public:
	simple_goal_decider(const vector<VERTEX> &candidates) : candidates(candidates)
	{
		sort(this->candidates.begin(), this->candidates.end());
	}
	bool operator()(const VERTEX &n)
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

goaldecider &get_goal_decider()
{
	cout << "Enter goal vertices (end with -1): ";
	int v;
	cin >> v;
	vector<VERTEX> goals;
	while (v != -1)
	{
		goals.push_back(v);
		cin >> v;
	}
	return *(new simple_goal_decider(goals));
}

void destroy_goaldecider(goaldecider &d)
{
	delete (simple_goal_decider *)&d;
}