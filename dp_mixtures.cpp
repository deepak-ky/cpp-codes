#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int                          long long
#define varname(name)                #name
#define mod                          1000000007
#define wer(x)                       cout<<"\n"<<varname(x)<<" here : "<<x
#define asdf(a,n)                    for(int i=0;i<n;i++)  cin>>a[i]
#define out(a,n)                     cout<<"\n"<<varname(a)<<" here is : ";for(int i=0;i<n;i++) cout<<a[i]<<" "; cout<<endl
int smoke_created(int *a, int i, int j, int dp[][102])
{
	if (i >= j)
	{
		return 0; //if there is a single element the smoke generated will be
	}
	if (dp[i][j] != -1) return dp[i][j];
	int f_ans = INT_MAX;
	for (int k = i; k < j; k++)
	{
		int ans = 0;
		int op1 = smoke_created(a, i, k, dp);
		int op2 = smoke_created(a, k + 1, j, dp);
		int csum1 = 0;
		for (int f = i; f <= k; f++)
		{
			csum1 += a[f] % 100;
		}
		int csum2 = 0;
		for (int f = (k + 1); f <= j; f++)
		{
			csum2 += a[f] % 100;
		}
		int op3 = (csum1 + csum2) % 100;
		ans = op1 + op2 + op3;
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
	// int t; cin>>t; while(t--)
	int dp[102][102];
	for (int i = 0; i < 102; i++)
	{
		for (int j = 0; j < 102; j++)
		{
			dp[i][j] = -1;
		}
	}
	int n;
	cin >> n;
	int a[n];
	asdf(a, n);
	cout << smoke_created(a, 0, n - 1, dp);
	return 0;
}
