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
int find_min_cost(int cost[][3])
{
	int dp[3][3];
	dp[0][0] = cost[0][0];
	for (int i = 1; i < 3; i++)
	{
		dp[0][i] = cost[0][i] + dp[0][i - 1];
	}
	for (int j = 1; j < 3; j++)
	{
		dp[j][0] = cost[j][0] + dp[0][j - 1];
	}
	for (int i = 1; i < 3; i++)
	{
		for (int j = 1; j < 3; j++)
		{
			dp[i][j] = cost[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	return dp[2][2];
}
int32_t main()
{

#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif

	int cost[3][3] = {{1, 5, 2},
		{7, 1, 1},
		{8, 1, 3}
	};
	cout << find_min_cost(cost);
	return 0;
}
