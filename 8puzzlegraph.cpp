#include "types.h"
#include <cmath>

class _8puzzlegraph:public graph
{
	static int getpos(int config)
	{
		for (int i = 3; i > 0; i--)
			for (int j = 3; j > 0; j--, config /= 10)
				if (config % 10 == 0)
					return i * 10 + j;
		return 0;
	}
	static int swap(int config, int newpos, int oldpos)
	{
		oldpos = (int)pow(1000, 3 - oldpos / 10) * ((int)pow(10, 3 - oldpos % 10));
		newpos = (int)pow(1000, 3 - newpos / 10) * ((int)pow(10, 3 - newpos % 10));
		int v = (config / newpos) % 10;
		return config + v * oldpos - v * newpos;
	}
	static int moveup(int config, const int &pos)
	{
		return swap(config, pos - 10, pos);
	}
	static int movedown(int config, const int &pos)
	{
		return swap(config, pos + 10, pos);
	}
	static int moveleft(int config, const int &pos)
	{
		return swap(config, pos - 1, pos);
	}
	static int moveright(int config, const int &pos)
	{
		return swap(config, pos + 1, pos);
	}

public:
	virtual vector<pair<int, int>> get_adjacent(const int &node, const int &cost)
	{
		vector<pair<int, int>> res;
		int p = getpos(node), c = cost + 1;
		switch (p / 10)
		{
		case 1:
			res.push_back(make_pair(movedown(node, p), c));
			break;
		case 2:
			res.push_back(make_pair(movedown(node, p), c));
			res.push_back(make_pair(moveup(node, p), c));
			break;
		case 3:
			res.push_back(make_pair(moveup(node, p), c));
			break;
		}
		switch (p % 10)
		{
		case 1:
			res.push_back(make_pair(moveright(node, p), c));
			break;
		case 2:
			res.push_back(make_pair(moveright(node, p), c));
			res.push_back(make_pair(moveleft(node, p), c));
			break;
		case 3:
			res.push_back(make_pair(moveleft(node, p), c));
			break;
		}
		return res;
	}
};

void print_8puzzleconfig(int puzzle)
{
	int L = 100000000;
	for (int i = 0; i < 3; i++)
	{
		cout << "+---+---+---+\n|";
		for (int j = 0; j < 3; j++, L /= 10)
		{
			int v = (puzzle / L) % 10;
			if (v)
				cout << ' ' << v << " |";
			else
				cout << "   |";
		}
		cout<<'\n';
	}
	cout << "+---+---+---+" << endl;
}

void printorder(vector<int> order)
{
	if (order.empty())
		cout << endl;
	const int L = order.size();
	cout << order[0];
	for (int i = 1; i < L; i++)
		cout << ',' << order[i];
	cout << endl;
}

void printpath(stack<int> path)
{
	if (path.empty())
		cout << endl;
	print_8puzzleconfig(path.top());
	path.pop();
	while (!path.empty())
	{
		cout << "\n      |\n      V\n" << endl;
		print_8puzzleconfig(path.top());
		path.pop();
	}
	cout << endl;
}

class _8puzzlegoaldecider : public goaldecider
{
public:
	bool operator()(const int &n)
	{
		return n == 123456780;
	}
};