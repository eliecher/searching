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
	virtual vector<pair<int, int>> get_adjacent(const int &, const int &) = 0;
};

class tree
{
	unordered_map<int, int> table;

public:
	tree();
	bool is_in(const int &n);
	int &operator[](const int &);
	stack<int> getpath(const int &n);
};

class genopentype
{
public:
	virtual void extract(int &node, int &cost, int &depth) = 0;
	// virtual void insert(const int &node, const int &cost, const int &depth) = 0;
	virtual void insert(const vector<pair<int, int>>& nodes,const int& depth) = 0;
	virtual void insert(const vector<pair<int, int>>& nodes,const vector<int>& depth) = 0;
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

extern graph& get_graph();
extern goaldecider& get_goal_decider();
extern int get_start_node();
extern void init_graph(graph&);
extern void destroy_graph(graph&);
extern void destroy_goaldecider(goaldecider&);
extern void orderprinter(const vector<int>&,ostream&);
extern void pathprinter(stack<int>&,ostream&);
extern void search_and_print(graph&,goaldecider&,int);
extern int get_lim();

#endif
#define TYPES_H