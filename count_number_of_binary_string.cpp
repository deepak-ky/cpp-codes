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
int dp[95];
void build_dp()
{
	int a[95];
	int b[95];
	a[0] = b[0] = 0;
	a[1] = b[1] = 1;
	dp[0] = 0;
	dp[1] = 2;
	for (int i = 2; i < 95; i++)
	{
		a[i] = a[i - 1] + b[i - 1];
		b[i] = a[i - 1];
		dp[i] = a[i] + b[i];
	}
}
int32_t main()
{

#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	build_dp();
	//out(dp, 7);
	test{
		int n;
		cin >> n;
		cout << dp[n] << endl;
	}
	return 0;
}
