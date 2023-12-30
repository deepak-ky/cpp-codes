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
int get_change_for(int n, int *coins, int size_of_coins_array, int *dp)
{
	if (n == 0)
	{
		return 0;
	}
	if (dp[n] != -1)
	{
		return dp[n];
	}
	int ans;
	ans = INT_MAX;
	for (int i = 0; i < size_of_coins_array; i++)
	{
		if (n - coins[i] >= 0)
		{
			int subprob = get_change_for(n - coins[i], coins, size_of_coins_array, dp);
			ans = min(ans, subprob + 1);
		}
	}
	return dp[n] = ans;
}
int32_t main()
{

#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	int dp[100];
	for (int i = 0; i < 100; ++i)
	{
		dp[i] = -1;
	}
	int coins[3] = {1, 7, 10};
	int n;
	cin >> n;
	cout << get_change_for(n, coins, 3, dp);

	return 0;
}
