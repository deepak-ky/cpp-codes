#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int                           long long
#define ab(a)                        (a<0)?(-1*a):a
#define faster                       ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define present(container, x)        container.find(x) != container.end()
#define watch(x)                     cout << (#x) << " is " << (x) << endl
#define mod                          1000000007
#define inf                          1e18
int32_t main()
{
	faster;
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
		if (n == 1 || n == 2 || n == 3)
		{
			cout << 1 << endl;
		}
		else {
			int i = 1;
			int j = 4;
			while (j != n || (j + 1) != n)
			{
				i++;
				j = j + 2;
			}
			cout << i << endl;
		}
	}
	return 0;
}