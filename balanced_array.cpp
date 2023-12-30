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
		int n;
		cin >> n;
		if ((n / 2) % 2 == 1)
		{
			cout << "NO" << endl;
		}
		else
		{
			cout << "YES" << endl;
			int sum1 = 0;
			for (int i = 2; i <= n; i = i + 2)
			{
				cout << i << " ";
				sum1 = sum1 + i;
			}
			int sum = 0;
			for (int i = 1; i < (n - 1); i = i + 2)
			{
				cout << i << " ";
				sum = sum + i;
			}
			cout << sum1 - sum;
			cout << endl;
		}
	}
	return 0;
}
