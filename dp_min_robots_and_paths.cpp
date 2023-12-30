#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int                          long long
#define varname(name)                #name
#define mod                          1000000007
#define wer(x)                       cout<<"\n"<<varname(x)<<" here : "<<x
#define test                         int t; cin>>t; while(t--)
#define asdf(a,n)                    for(int i=0;i<n;i++)  cin>>a[i]
#define out(a,n)                     cout<<"\n"<<varname(a)<<" here is : ";for(int i=0;i<n;i++) cout<<a[i]<<" "; cout<<endl
int dp[1002][1002];
int min_ways_to_reach(int m, int n)
{

	if (dp[0][0] == -1)
	{
		return 0;
	}


	for (int i = 0; i < n; i++)
	{
		if (dp[0][i] == -1)
		{

			break;
		}
		dp[0][i] = 1;
	}
	for (int i = 0; i < m; i++)
	{
		if (dp[i][0] == -1)
		{
			break;
		}
		dp[i][0] = 1;
	}

	for (int i = 1; i < m; i++)
	{
		for (int j = 1; j < n; j++)
		{
			if (dp[i][j] == -1)
			{
				continue;
			}
			dp[i][j] = 0;
			if (dp[i][j - 1] != -1)
			{
				dp[i][j] = dp[i][j - 1] % mod;
			}
			if (dp[i - 1][j] != -1)
			{
				dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;
			}
		}

	}
	if (dp[m - 1][n - 1] == -1)
	{
		return 0;
	}
	/*	for (int i = 0; i <= m; i++)
		{
			for (int j = 0; j <= n; j++)
			{
				cout << dp[i][j] << " ";
			}
			cout << endl;

		}*/
	return dp[m - 1][n - 1];
}

int32_t main()
{

#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	memset(dp, 0, sizeof dp);
	int m, n, p;
	cin >> m >> n >> p;
	for (int i = 0; i < p; i++)
	{
		int x;
		int y;
		cin >> x >> y;
		dp[x - 1][y - 1] = -1;
	}
	cout << min_ways_to_reach(m, n);
	return 0;
}
