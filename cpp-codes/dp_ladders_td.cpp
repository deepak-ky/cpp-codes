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
int max_ways(int n, int k, int *dp)
{
	if (n == 0)
	{
		return 1;
	}
	if (dp[n] != -1)
	{
		return dp[n];
	}
	int ans = 0;
	for (int i = 1; i <= k; i++)
	{
		if (n - i >= 0)
		{
			ans += max_ways(n - i, k, dp);
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
	for (int i = 0; i < 100; i++)
	{
		dp[i] = -1;
	}
	int n, k;
	cin >> n >> k;
	cout << max_ways(n, k, dp);
	return 0;
}
