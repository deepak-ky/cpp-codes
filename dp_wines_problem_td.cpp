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
#define N 5
int maximum_profit(int *p, int i, int j, int dp[][100], int y)
{
	//if(i>j overshoots j)
	if (i > j)
	{
		return 0;
	}
	//Look UP case
	if (dp[i][j] != -1)
	{
		return dp[i][j];
	}
	int ans = INT_MIN;
	int op1 = p[i] * y + maximum_profit(p, i + 1, j, dp, y + 1);
	int op2 = p[j] * y + maximum_profit(p, i, j - 1, dp, y + 1);
	ans = max(op1, op2);
	return dp[i][j] = ans;
}
int32_t main()
{

#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	int dp[100][100];
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			dp[i][j] = -1;
		}
	}
	int p[5] = {2, 3, 5, 1, 4};
	int y = 1;
	cout << maximum_profit(p, 0, 4, dp, y);
	return 0;
}
