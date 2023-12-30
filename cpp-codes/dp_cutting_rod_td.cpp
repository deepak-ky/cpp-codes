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
int max_profit(int n, int *p, int *dp)
{
	if (n == 0)
	{
		return 0;
	}
	if (dp[n] != -1)
	{
		return dp[n];
	}
	int ans = INT_MIN;
	for (int i = 1; i <= n; i++)
	{
		int w = p[i - 1] + max_profit(n - i, p, dp);
		ans = max(w, ans);
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
	int n;
	cin >> n;
	int p[n];
	for (int i = 0; i < n; i++)
	{
		cin >> p[i];
	}
	cout << max_profit(n, p, dp);
	return 0;
}
