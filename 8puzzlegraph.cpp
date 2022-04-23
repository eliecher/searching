#include "types.h"
#include <cmath>

unordered_map<int, string> opnamemapping;

class _8puzzlegraph : public graph
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
	_8puzzlegraph()
	{
		opnamemapping[0] = "INITIAL BOARD CONFIG IS";
		opnamemapping[1] = "      |     MOVE UP\n      V";
		opnamemapping[2] = "      |     MOVE DOWN\n      V";
		opnamemapping[3] = "      |     MOVE LEFT\n      V";
		opnamemapping[4] = "      |     MOVE RIGHT\n      V";
	}
	virtual vector<pair<pair<int, int>, int>> get_adjacent(const int &node, const int &cost)
	{
		vector<pair<pair<int, int>, int>> res;
		int p = getpos(node), c = cost + 1;
		switch (p / 10)
		{
		case 1:
			res.push_back(make_pair(make_pair(movedown(node, p), c), 2));
			break;
		case 2:
			res.push_back(make_pair(make_pair(movedown(node, p), c), 2));
			res.push_back(make_pair(make_pair(moveup(node, p), c), 1));
			break;
		case 3:
			res.push_back(make_pair(make_pair(moveup(node, p), c),1));
			break;
		}
		switch (p % 10)
		{
		case 1:
			res.push_back(make_pair(make_pair(moveright(node, p), c), 4));
			break;
		case 2:
			res.push_back(make_pair(make_pair(moveright(node, p), c), 4));
			res.push_back(make_pair(make_pair(moveleft(node, p), c), 3));
			break;
		case 3:
			res.push_back(make_pair(make_pair(moveleft(node, p), c), 3));
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
		cout << '\n';
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

void printpath(stack<pair<int,int>> path)
{
	if (path.empty())
		cout << endl;
	while (!path.empty())
	{
		cout << opnamemapping[path.top().first]<<endl;
		print_8puzzleconfig(path.top().second);
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

class misplaced_count_heuristic
{
public:
	int operator()(const int &v)
	{
		int copy = v, target = 123456780, h = 0;
		for (int i = 9; i > 0; i--)
		{
			if (copy % 10 != target % 10)
				h++;
			copy /= 10;
			target /= 10;
		}
		return h;
	}
};

class manhattan_total_heuristic
{
public:
	int operator()(const int &v)
	{
		int copy = v, target = 123456780, h = 0;
		int r = 2, c = 2;
		for (int i = 9; i > 0; i--)
		{
			int tr, tc;
			if (copy % 10 == 0)
			{
				tr = 2, tc = 2;
			}
			else
			{
				tr = (copy % 10 - 1) / 3;
				tc = (copy % 10 - 1) % 3;
			}
			h += abs(tr - r) + abs(tc - c);
			copy /= 10;
			target /= 10;
			c--;
			if (c == -1)
				r--, c = 2;
		}
		return h;
	}
};