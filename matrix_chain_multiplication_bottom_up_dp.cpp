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

int min_cost(int *a, int n)
{
	int dp[n][n];
	for (int i = 0; i < n; i++)
	{
		dp[i][i] = 0;
	}

	for (int level = 2; level < n; level++)
	{
		for (int i = 1; i < n - level + 1; i++)
		{
			int j = i + level - 1;
			dp[i][j] = INT_MAX;
			for (int k = i; k <= j - 1; k++)
			{
				int q = dp[i][k] + dp[k + 1][j] + (a[i - 1] * a[k] * a[j]);
				dp[i][j] = min(dp[i][j], q);
			}
		}
	}

	return dp[1][n - 1];
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
	int a[] = {4, 2, 3, 1, 3};
	int n = 5;
	cout << min_cost(a, 5);
	return 0;
}
