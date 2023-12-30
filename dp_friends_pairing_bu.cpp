#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int                          long long
#define varname(name)                #name
#define mod                          1000000007
#define wer(x)                       cout<<"\n"<<varname(x)<<" here : "<<x
#define asdf(a,n)                    for(int i=0;i<n;i++)  cin>>a[i]
#define out(a,n)                     cout<<"\n"<<varname(a)<<" here is : ";for(int i=0;i<n;i++) cout<<a[i]<<" "; cout<<endl
int friends_pairing(int n)
{
	cout << "hello";
	int dp[15] = {};
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i < 10; i++)
	{
		dp[i] = dp[i - 1] + ((i - 1) * dp[i - 2]);
	}
	out(dp, 10);
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
	//int t; cin>>t; while(t--)
	int n;
	cin >> n;
	cout << friends_pairing(n);
	return 0;
}
