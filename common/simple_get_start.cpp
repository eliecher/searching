#include "types.h"
#include <climits>
VERTEX get_start_vertex()
{
	cout << "Enter Start: ";
	VERTEX lim = VERTEX_MAX;
	cin >> lim;
	return lim;
}