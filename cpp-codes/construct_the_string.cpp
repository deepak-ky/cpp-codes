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
		lli n, a, b;
		cin >> n >> a >> b;
		for (lli i = 0; i < n; i++)
		{
			cout << char('a' + i % b);
		}

		cout << endl;
	}
	return 0;
}
