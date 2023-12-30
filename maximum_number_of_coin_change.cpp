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

int maximum_number_of_coin_change_ways(int *a, int len, int n)
{
	int dp[n + 1];
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	for (int i = 0; i < len; i++)
	{
		for (int j = a[i]; j <= n; j++)
		{
			dp[j] += dp[j - a[i]];
		}
	}
	return dp[n];
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
		int n;
		cin >> n;
		int *a = new int[n];
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		int w;
		cin >> w;
		cout << maximum_number_of_coin_change_ways(a, n, w) << endl;
	}
	return 0;
}
