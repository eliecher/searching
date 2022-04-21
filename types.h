#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <ctype.h>
#include <climits>
#include <unordered_set>
#include <unordered_map>
using namespace std;
#ifndef TYPES_H
typedef unsigned int COST;
typedef unsigned int VERTEX;
#define COST_MAX UINT_MAX
#define COST_MIN 0
#define VERTEX_MAX UINT_MAX
#define VERTEX_MIN 0

struct treenode
{
	VERTEX parent;
	int operation;
	treenode(const VERTEX &parent = VERTEX_MAX, const int &operation = INT_MAX);
};
struct solnode
{
	VERTEX vertex;
	COST cost;
	solnode(const VERTEX &vertex = VERTEX_MAX, const COST &cost = COST_MAX);
};


struct opennode
{
	solnode s;
	int depth;
	opennode(const solnode &s, const int &depth);
};
struct graph_node
{
	solnode s;
	int operation;
	graph_node(const solnode &s, const int &operation);
};

class myexcep : public exception
{

public:
	string mssg;
	myexcep(const string &errmssg) : exception(), mssg(errmssg) {}
};

class graph
{
protected:
	unordered_map<int, string> operation_names;

public:
	virtual vector<graph_node> get_adjacent(const solnode &) = 0;
};

class tree
{
protected:
	unordered_map<VERTEX, treenode> table;

public:
	tree();
	bool is_in(const VERTEX &n);
	treenode &operator[](const VERTEX &);
	stack<treenode> getpath(const VERTEX &n);
};

class genopentype
{
public:
	virtual opennode extract() = 0;
	virtual void insert(const vector<opennode> &) = 0;
	// virtual void insert(const vector<solnode> &,const int& depth) = 0;
	virtual bool unempty() = 0;
};

class goaldecider
{
public:
	virtual bool operator()(const VERTEX &) = 0;
};

extern graph &get_graph();
extern goaldecider &get_goal_decider();
extern VERTEX get_start_vertex();
extern void init_graph(graph &);
extern void destroy_graph(graph &);
extern void destroy_goaldecider(goaldecider &);
extern void orderprinter(const vector<VERTEX> &, ostream &);
extern void pathprinter(stack<treenode> &, ostream &);
extern void search_and_print(graph &, goaldecider &, VERTEX, int);
extern int get_lim();

#endif
#define TYPES_H