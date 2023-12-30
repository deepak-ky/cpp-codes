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

bool is_subset_sum(int *a, int n, int w)
{
	bool dp[n + 1][w + 1];
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i < w + 1; i++)
	{
		dp[0][i] = 0;
	}
	for (int i = 0; i < n + 1; i++)
	{
		dp[i][0] = 1;
	}
	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < w + 1; j++)
		{
			if (a[i - 1] > j)
			{
				dp[i][j] = dp[i - 1][j];
			}
			else
			{
				int op1 =  dp[i - 1][j - a[i - 1]];
				int op2 =  dp[i - 1][j];
				if (op1 == 1 || op2 == 1) dp[i][j] = 1;
				else dp[i][j] = 0;
			}
		}

	}
	return dp[n][w];
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
	int w;
	cin >> w;
	int n;
	cin >> n;
	int *a = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	if (is_subset_sum(a, n, w))
	{
		cout << "A subset with the given sum is present";
	}
	else cout << "Not present";
	return 0;
}
