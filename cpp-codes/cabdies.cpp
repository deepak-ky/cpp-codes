#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main()
{
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	lli t;
	cin >> t;
	while (t--)
	{
		lli n;
		cin >> n;
		if (n & 1)
		{
			cout << n / 2 << endl;
		}
		else
			cout << n / 2 - 1 << endl;

	}
	return 0;
}
