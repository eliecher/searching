#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <unordered_set>
#include <unordered_map>
using namespace std;
#ifndef TYPES_H
class myexcep : public exception
{

public:
	string mssg;
	myexcep(const string &errmssg) : exception(), mssg(errmssg) {}
};

class graph
{
public:
	virtual vector<pair<pair<int, int>, int>> get_adjacent(const int &, const int &) = 0;
};

class tree
{
	unordered_map<int, int> table;
	unordered_map<int, int> optable;

public:
	tree();
	bool is_in(const int &n);
	int &operator[](const int &);
	stack<pair<int, int>> getpath(const int &n);
	int &op(const int &);
};

class genopentype
{
public:
	virtual void extract(int &node, int &cost, int &depth) = 0;
	virtual void insert(const int &node, const int &cost, const int &depth) = 0;
	virtual bool unempty() = 0;
};
struct search_node
{
	int v, c, d;
	search_node(const int &v, const int &c, const int &d) : v(v), c(c), d(d) {}
};

class goaldecider
{
public:
	virtual bool operator()(const int &n) = 0;
};
#endif
#define TYPES_H