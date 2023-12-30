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
int ways_to_reach(int n, int k)
{
	int dp[n + 1];
	memset(dp, 0, sizeof(dp));
	dp[0] = 1; //base case
	for (int i = 1; i <= k; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			if ((j - i) >= 0)
			{
				dp[j] += dp[j - i];
			}
		}
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
	cout << ways_to_reach(n, k);
	return 0;
}
