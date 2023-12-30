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
int grid[1002][1002] = {};
int min_ways_to_reach(int maze[][1002], int m, int n)
{
	int dp[m][n];
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			dp[i][j] = INT_MAX;
		}
	}
	dp[0][0] = 1;
	for (int i = 1; i < m; i++)
	{
		if (maze[0][i] != -1)
		{
			dp[0][i] = 1;
		}
		else break;
	}
	for (int i = 1; i < n; i++)
	{
		if (maze[i][0] != -1)
		{
			dp[i][0] = 1;
		}
		else break;
	}
	for (int i = 1; i < m; i++)
	{
		for (int j = 1; j < n; j++)
		{
			if (maze[i][j] != -1)
			{
				int op1 = 0;
				if (dp[i - 1][j] != (INT_MAX))
				{
					op1 = dp[i - 1][j];
				}
				int op2 = 0;
				if (dp[i][j - 1] != INT_MAX)
				{
					op2 = dp[i][j - 1];
				}
				dp[i][j] = op1 + op2;

			}
			else
				dp[i][j] = INT_MAX;
		}
		cout << endl;
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
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
	int m;
	int n;
	int p;
	cin >> m >> n;


	cin >> p;
	while (p--)
	{
		int x;
		int y;
		cin >> x >> y;
		x--; y--;
		grid[x][y] = -1;
	}
	cout << min_ways_to_reach(grid, m, n) % mod;
	return 0;
}
