#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int                          long long
#define watch(var,x)                 cout <<"\nValue of x here is : "<<(x) << endl
#define mod                          1000000007
int32_t main()
{

#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	int t;
	cin >> t;
	while (t--)
	{
		int n, a, b, c, d;
		cin >> n >> a >> b >> c >> d;
		int ming = a - b;
		int maxg = a + b;
		int mins = c - d;
		int maxs = c + d;
		if (((ming * n) > maxs) || ((maxg * n) < mins))
		{
			cout << "No" << endl;
		}
		else
		{
			cout << "Yes" << endl;
		}
	}
	return 0;
}
