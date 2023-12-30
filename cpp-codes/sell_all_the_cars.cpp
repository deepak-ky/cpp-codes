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
		vector<int> v;
		int profit = 0;
		for (int i = 0; i < n; i++)
		{
			int w;
			cin >> w;
			v.push_back(w);
		}
		sort(v.begin(), v.end());
		int i = n - 1;
		while (i >= 0)
		{

			profit = profit + v.back();

			v.pop_back();
			for (int j = 0; j < v.size(); j++)
			{
				if (v[j] != 0)
				{v[j] = v[j] - 1;}
			}
			i--;
		}
		cout << profit % mod << endl;
	}
	return 0;
}