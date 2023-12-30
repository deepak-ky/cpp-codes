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
const int last = 107;
int dp[last];
void fill_dp()
{

	for (int i = 0; i < last; i++)
	{
		dp[i] = -1;
	}
	dp[1] = 0;
	for (int i = 2; i < last; i++)
	{
		int op1, op2, op3;
		op1 = op2 = op3 = INT_MAX;
		if (i % 3 == 0)
		{
			op1 = dp[i / 3];
		}
		if ( i % 2 == 0)
		{
			op2 = dp[i / 2];
		}
		op3 = dp[i - 1];

		dp[i] = min(op1, min(op2, op3)) + 1;
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
	int p = 1;
	fill_dp();
	test
	{
		int n;
		cin >> n;
		cout  << "Case " << p << ": " << dp[n] << endl;
		p++;
	}

	return 0;
}
