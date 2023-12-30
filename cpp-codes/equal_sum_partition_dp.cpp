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
bool fesq(int *a, int idx, int n, int target)
{
	bool dp[n + 1][target + 1];
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < target + 1; i++) dp[0][i] = 0;
	for (int i = 0; i < n + 1; i++)      dp[i][0] = 1;
	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < target + 1; j++)
		{
			if (a[i - 1] > j)
			{
				dp[i][j] = dp[i - 1][j];
			}
			else
			{
				bool op1 = dp[i - 1][j  - a[i - 1]];
				bool op2 = dp[i - 1][j];
				if (op1 || op2) dp[i][j] = 1; else dp[i][j] = 0;
			}
		}
	}
	return dp[n][target];
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
	int n;
	cin >> n;
	int *a = new int[n];
	int sum_needed = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		sum_needed += a[i];
	}
	if (sum_needed & 1) cout << "No";
	else
	{
		if (fesq(a, 0, n, sum_needed / 2))
		{
			cout << "Yes";
		}
		else cout << "No";
	}
	return 0;
}
