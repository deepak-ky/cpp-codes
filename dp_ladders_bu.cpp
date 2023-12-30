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
int make_profit(int n, int k)
{
	int dp[100];
	for (int i = 0; i < 100; i++)
	{
		dp[i] = -1;
	}
	dp[0] = 1; //base case
	for (int i = 1; i <= n; i++)
	{
		int ans = 0;
		for (int j = 1; j <= k; j++)
		{
			if ((i - j) >= 0)
			{
				ans += dp[i - j];
			}
		}
		dp[i] = ans;
	}
	return dp[n];

}
int make_profit_optimized(int n, int k)
{
	int dp[100] = {0};
	dp[0] = dp[1] = 1;
	for (int i = 2; i <= k; i++)
	{
		dp[i] = 2 * dp[i - 1];
	}
	for (int i = k + 1; i <= n; i++)
	{
		dp[i] = 2 * dp[i - 1] - dp[i - k - 1];
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
	int n, k;
	cin >> n >> k;
	cout << make_profit_optimized(n, k);
	return 0;
}
