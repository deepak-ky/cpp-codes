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
	lli inc = 0;
	while (t--)
	{
		lli n, amt;
		cin >> n >> amt;
		lli a[n];
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		lli ans = 0;
		sort(a, a + n);
		for (int i = 0; i < n; i++)
		{
			if (a[i] <= amt)
			{
				ans++;
				amt -= a[i];
			}
		}
		cout << "Case #" << ++inc << ": " << ans << endl;
	}
	return 0;
}