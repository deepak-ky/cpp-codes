#include<iostream>
using namespace std;
int main()
{

#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	int x;
	cin >> x;
	cout << (2 + x);
	return 0;
}
