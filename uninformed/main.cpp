#include "types.h"

int main()
{
	graph &g = get_graph();
	init_graph(g);
	int start = get_start_node();
	goaldecider &dec = get_goal_decider();
	search_and_print(g, dec, start);
	destroy_graph(g);
	destroy_goaldecider(dec);
}