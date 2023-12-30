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
int get_change_for(int n, int *coins, int size_of_coins)
{
	int dp[100];
	for (int i = 0; i < 100; i++)
	{
		dp[i] = -1;
	}
	dp[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		dp[i] = INT_MAX;
		for (int j = 0; j < size_of_coins; j++)
		{
			if (i - coins[j] >= 0)
			{
				int subprob = dp[(i - coins[j])];
				dp[i] = min(dp[i], subprob + 1);
			}
		}
	}
	for (auto x : dp)
	{
		if (x == INT_MAX)
		{
			cout << "INF" << " ";
		}
		else cout << x << " ";
	}
	return dp[n];
}
int32_t main()
{

#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	int coins[] = {9, 6, 5};
	int size_of_coins = sizeof(coins) / sizeof(int);
	int n;
	cin >> n;
	cout << get_change_for(n, coins, size_of_coins);
	return 0;
}
