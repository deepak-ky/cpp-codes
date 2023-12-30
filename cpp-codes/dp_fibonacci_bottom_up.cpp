#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int                          long long
#define varname(name)                #name
#define mod
#define wer(x)                       cout<<"\n"<<varname(x)<<" here : "<<x
#define test                         int t; cin>>t; while(t--)
#define asdf(a,n)                    for(int i=0;i<n;i++)  cin>>a[i]
#define out(a,n)                     cout<<"\n"<<varname(a)<<" here is : ";for(int i=0;i<n;i++) cout<<a[i]<<" "; cout<<endl;
int fib_bu(int n)
{
	int dp[16] = {0};
	dp[0] = 0;
	dp[1] = 1;
	for (int i = 2; i < 16; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	return (dp[n]);
}
int fib_sp_opt(int n)
{
	if (n == 1 || n == 0)
	{
		return n;
	}
	int a = 0;
	int b = 1;
	int c = 0;
	for (int i = 2; i <= n; i++)
	{
		c = a + b;
		a = b;
		b = c;
	}
	return c;
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
	//cout << endl << fib_bu(n);
	cout << endl << fib_sp_opt(n);
	return 0;
}
