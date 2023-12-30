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

int min_coins_to_change(int * coins, int n, int len)
{
	int dp[n + 1];
	for (int i = 0; i < n + 1; i++)
	{
		dp[i] = INT_MAX;
	}
	dp[0] = 0;/*
	for (auto x : dp)
	{
		if (x == INT_MAX)
		{
			cout << "INF" << " ";
		}
		else cout << x << " ";
	}
	cout << endl;*/
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < len; j++)
		{
			if (i >= coins[j])
			{
				//if ( dp[i - coins[j]] != INT_MAX || i - coins[j] == 0)
				{
					//no need for the above line because minimum of infinity and infinity + 1 is infinity only
					dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
				}
			}
		}
	}

	/*for (auto x : dp)
	{
		if (x == INT_MAX)
		{
			cout << "INF" << " ";
		}
		else cout << x << " ";
	}

	cout << endl;
	*/if (dp[n] == INT_MAX) return - 1;

	else return dp[n];
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
		int v;
		cin >> v;
		int c;
		cin >> c;
		int * coins = new int[c];
		for (int i = 0; i < c; i++)
		{
			cin >> coins[i];
		}
		cout << min_coins_to_change(coins, v, c) << endl;
	}
	return 0;
}
