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

int maximize_profit(int n, int * price)
{
	int dp[n + 1];
	memset(dp, -1, sizeof(dp));
	dp[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		int ans = INT_MIN;
		for (int j = 1; j <= i; j++)
		{
			ans = max(ans , (price[j - 1]) + dp[i - j] );
		}
		dp[i] = ans;
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

	int n;
	cin >> n;
	int *a = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	cout << maximize_profit(n, a);
	return 0;
}
