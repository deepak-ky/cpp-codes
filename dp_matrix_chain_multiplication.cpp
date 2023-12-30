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
int min_cost(int *a, int i, int j, int dp[][10])
{
	if (i >= j)
	{
		return 0;
	}
	if (dp[i][j] != -1)
	{
		return dp[i][j];
	}
	int f_ans = INT_MAX;
	for (int k = i; k <= (j - 1); k++)
	{
		int op1 = min_cost(a, i, k, dp);
		int op2 = min_cost(a, k + 1, j, dp);
		int op3 = a[i - 1] + a[k] + a[j];
		int ans = op1 + op2 + op3;
		f_ans = min(ans, f_ans);
	}
	return dp[i][j] = f_ans;
}
int32_t main()
{

#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	int dp[10][10];
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			dp[i][j] = -1;
		}
	}
	int a[5] = {4, 2, 3, 1, 3};
	cout << min_cost(a, 1, 4, dp);
	return 0;
}
