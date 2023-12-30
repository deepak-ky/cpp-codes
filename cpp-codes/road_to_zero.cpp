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
		int x1, y1, a, b;
		cin >> x1 >> y1 >> a >> b;
		int x = min(x1, y1);
		int y = max(x1, y1);
		int sum = 0;

		if ((x == 0 ) || ( y == 0) )
		{

			sum = sum + (max(x, y) * a);
			cout << sum << endl;
		}
		else
		{
			int ans = abs(x - y) * a;
			ans += min(min(x, y) * a * 2, min(x, y) * b);
			cout << ans << endl;
		}

	}
	return 0;
}
