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

int min_steps_to_reach_one(int n)
{
	int dp[n + 2];
	memset(dp, -1, sizeof(dp));
	dp[0] = 0;
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;
	for (int i = 4; i <= n; i++)
	{
		int op1 = 1 + dp[i - 1];
		int op2 = INT_MAX;
		if (i % 2 == 0)
		{
			op2 = 1 + dp[i / 2];
		}
		int op3 = INT_MAX;
		if (i % 3 == 0)
		{
			op3 = 1 + dp[i / 3];
		}
		dp[i] = min(op1, min(op2, op3));
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
		cout << min_steps_to_reach_one(n) << endl;
	}
	return 0;
}
