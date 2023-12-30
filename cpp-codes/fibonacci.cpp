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
int top_down_fib(int n, int *dp)
{
	if (n == 1 || n == 0)
	{
		return n;
	}
	if (dp[n] != -1)
	{
		return dp[n];
	}
	int ans = top_down_fib(n - 1, dp) + top_down_fib(n - 2, dp);
	return dp[n] = ans;
}
int bottom_up_fib(int n)
{
	int dp[10];
	memset(dp, -1, sizeof(dp));
	dp[0] = 0;
	dp[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
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
	int dp[10];
	memset(dp, -1, sizeof(dp));
	int n;
	cin >> n;
	cout << "The " << n << "th fibonacci number is : " << top_down_fib(n, dp) << endl;
	cout << "The " << n << "th fibonacci number is : " << bottom_up_fib(n) << endl;
	return 0;
}
