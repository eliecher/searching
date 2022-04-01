#include "types.h"
#include <climits>
int get_lim()
{
	cout << "Enter Limit: ";
	unsigned int lim = INT_MAX;
	cin >> lim;
	return lim;
}