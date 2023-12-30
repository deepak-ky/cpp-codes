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
int n = 4;
int dp[16][4];
int dist[10][10] = {
	{0, 20, 42, 25},
	{20, 0, 30, 34},
	{42, 30, 0, 10},
	{25, 34, 10, 0}
};
int visited_all = (1 << n) - 1;
int tsp(int mask, int pos)
{
	if (mask == visited_all)
	{
		return dist[pos][0];
	}
	if (dp[mask][pos] != -1)
	{
		return dp[mask][pos];
	}
	//try to visit each node
	int ans = INT_MAX;
	for (int city = 0; city < n; city++)
	{
		if ((mask & (1 << city)) == 0)
		{
			int newAns = dist[pos][city] + tsp( mask | (1 << city) , city);
			ans = min(ans, newAns);
		}
	}
	return dp[mask][pos] = ans; //saving the result and returning
}
int32_t main()
{
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	for (int i = 0; i < (1 << n); i++)
	{
		for (int j = 0; j < n; j++)
		{
			dp[i][j] = -1;
		}
	}
	cout << tsp(1, 0);

	return 0;
}
