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
void solve(vector<int> v1, vector<int> v2, vector<int> v3, int minn)
{
	for (int i = 0; i < v2.size(); i++)
	{
		int lb = v1[0];
		for (int j = 1; j < v1.size(); j++)
		{
			if (v1[j] <= v2[i])
			{
				lb = v1[0];
			}
		}
		int v3size = v3.size();
		int ub = v[v3size - 1];
		for (int j = v3size - 2; j >= 0; j--)
		{
			if (v3[j] >= v2[i])
			{
				ub = v3[0];
			}
		}
	}

}
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
		int nr, ng, nb;
		cin >> nr >> ng >> nb;
		vector<int> v1, v2, v3;
		for (int i = 0; i < nr; i++)
		{
			int w;
			cin >> w;
			v1.push_back(w);
		}
		for (int i = 0; i < ng; i++)
		{
			int w;
			cin >> w;
			v2.push_back(w);
		}
		for (int i = 0; i < nb; i++)
		{
			int w;
			cin >> w;
			v3.push_back(w);
		}
		sort(v1.begin(), v1.end());
		sort(v2.begin(), v2.end());
		sort(v3.begin(), v3.end());
		int minn = -500;
		solve(v1, v2, v3, minn);
	}
	return 0;
}