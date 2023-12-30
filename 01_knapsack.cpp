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
int knap_sack(int *val, int *wt, int n, int w)
{
	if (n == 0 || w == 0)
	{
		return 0;
	}
	if (dp[n][w] != -1)
	{
		return dp[n][w];
	}
	else
	{
		if (wt[n - 1] > w)
		{
			return dp[n][w] = knap_sack(val, wt, n - 1, w);
		}
		else return dp[n][w] = max( (val[n - 1]) + knap_sack(val, wt, n - 1, w - wt[n - 1]) , knap_sack(val, wt, n - 1, w));
	}
}
int32_t main()
{
//ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	test
	{
		memset(dp, -1, sizeof(dp));
		int n;
		cin >> n;
		int w;
		cin >> w;
		int val[n];
		for (int i = 0; i < n; i++)
		{
			cin >> val[i];
		}
		int wt[n];
		for (int i = 0; i < n; i++)
		{
			cin >> wt[i];
		}
		cout << knap_sack(val, wt, n, w);
	}

	return 0;
}
