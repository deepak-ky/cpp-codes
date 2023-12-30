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
int max_profit_bu(int n, int *p)
{
	int dp[100];
	for (int i = 0; i < n; i++)
	{
		dp[i] = -1;
	}
	dp[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		int ans = INT_MIN;
		for (int j = 1; j <= n; j++)
		{
			if (i - j >= 0)
			{
				int w = p[j - 1] + dp[i - j];
				ans = max(w, ans);
			}
		}
		dp[i] = ans;
	}
	out(dp, n + 1);
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
	int n;
	cin >> n;
	int p[n];
	for (int i = 0; i < n; i++)
	{
		cin >> p[i];
	}
	cout << max_profit_bu(n, p);
	return 0;
}
