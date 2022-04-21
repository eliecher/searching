#include "types.h"
#define NUM_SOLS 1

int main()
{
	graph &G = get_graph();
	init_graph(G);
	VERTEX start = get_start_vertex();
	goaldecider &decider = get_goal_decider();
	search_and_print(G, decider, start, NUM_SOLS);
	destroy_graph(G);
	destroy_goaldecider(decider);
}