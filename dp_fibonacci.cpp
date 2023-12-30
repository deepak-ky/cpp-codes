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



int fib(int n, int *dp)
{
	if (n == 0 || n == 1)
	{
		return n;
	}
	if (dp[n] != -1)
	{
		return dp[n];
	}
	int ans;
	ans = fib(n - 1, dp) + fib(n - 2, dp);
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
	int dp[10];
	for (int w = 0; w < 10; w++)
	{
		dp[w] = -1;
	}
	int n;
	cin >> n;
	cout << endl << fib(n, dp);
	return 0;
}
