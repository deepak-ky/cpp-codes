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
int dp[10002];
int min_steps_to_reach_one(int n)
{
	if (n == 1)
	{
		return 0;
	}
	if ( n == 2 || n == 3)
	{
		return 1;
	}
	if (dp[n] != -1)
	{
		return dp[n];
	}
	int op1 = 1 + min_steps_to_reach_one(n - 1);
	int op2 = INT_MAX;
	int op3 = INT_MAX;
	if (n % 2 == 0)
	{
		op2 = 1 + min_steps_to_reach_one(n / 2);
	}
	if (n % 3 == 0)
	{
		op3 = 1 + min_steps_to_reach_one(n / 3);
	}
	return dp[n] = min(op1, min(op2, op3));

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
		memset(dp, -1, sizeof(dp));
		int n;
		cin >> n;
		cout << min_steps_to_reach_one(n) << endl;
	}
	return 0;
}
