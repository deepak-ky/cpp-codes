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
		lli x, m, n;
		cin >> x >> m >> n;
		while (m != 0 && x > 10)
		{

			x = x / 2;
			x = x + 10;
			m--;
		}
		lli w = x - (n * 10);
		if (w == 0 || w < 0)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}
	return 0;
}
