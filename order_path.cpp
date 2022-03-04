#include <iostream>
#include <vector>
#include <stack>
using namespace std;
void printsimpleorder(vector<int> order)
{
	if (order.empty())
		cout << endl;
	const int L = order.size();
	cout << order[0];
	for (int i = 1; i < L; i++)
		cout << ',' << order[i];
	cout << endl;
}
void printsimplepath(stack<int> st)
{
	if (st.empty())
		cout << endl;
	cout << st.top();
	st.pop();
	while (!st.empty())
	{
		cout << "->" << st.top();
		st.pop();
	}
	cout << endl;
}