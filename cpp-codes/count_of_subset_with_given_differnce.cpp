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

int count_of_subset_sum_equal(int *a, int n, int w)
{
	int dp[n + 1][w + 1];
	memset(dp, -1, sizeof(dp));

	for (int i = 0; i < w + 1; i++) dp[0][i] = 0;
	for (int i = 0; i < n + 1; i++) dp[i][0] = 1;

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
				dp[i][j] = dp[i - 1][j - a[i - 1]] + dp[i - 1][j];
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
	int diff;
	cin >> diff;
	int n;
	cin >> n;
	int total = 0;
	int *a = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		total += a[i];
	}
	int find = (total + diff) / 2;
	wer(find);
	cout << count_of_subset_sum_equal(a, n, find);
	return 0;
}
