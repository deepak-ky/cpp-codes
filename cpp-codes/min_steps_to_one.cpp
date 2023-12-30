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
int min_steps_to_one(int n)
{
	int dp[100007];
	for (int i = 0; i < 100007; i++)
	{
		dp[i] = -1;
	}
	dp[1] = 0; dp[2] = 1; dp[3] = 1;
	for (int i = 4; i <= n; i++)
	{
		if (i % 3 == 0)
		{
			dp[i] = dp[i / 3] + 1;
		}
		else if (i % 2 == 0)
		{
			dp[i] = dp[i / 2] + 1;
		}
		else
		{
			dp[i] = dp[i - 1] + 1;
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
	int p = 1;
	test
	{
		int n;
		cin >> n;
		cout << " Case " << p << ": " << min_steps_to_one(n) << endl;
		p++;
	}
	return 0;
}
