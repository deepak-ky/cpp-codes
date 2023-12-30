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

int min_subset_sum_diff(int *a, int n)
{
	int total = 0;
	for (int i = 0; i < n; i++)
	{
		total += a[i];
	}

	bool dp[n + 1][total + 1];
	memset(dp, -1, sizeof(dp));

	for (int i = 0; i < total + 1; i++)
	{
		dp[0][i] = false;
	}
	for (int i = 0; i < n + 1; i++)
	{
		dp[i][0] = true;
	}

	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < total + 1; j++)
		{
			if (a[i - 1] > j)
			{
				dp[i][j] = dp[i - 1][j];
			}
			else
			{
				if (dp[i - 1][j - a[i - 1]] || dp[i - 1][j])
					dp[i][j] = true;

				else dp[i][j] = false;
			}
		}
	}

	int largest_less_than_half_subset_value;
	for (int j = total / 2; j >= 0; j--)
	{
		if (dp[n][j])
		{
			largest_less_than_half_subset_value = j;
			break;
		}
	}
	//cout << largest_less_than_half_subset_value << endl;
	return (total - 2 * largest_less_than_half_subset_value);
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
	test {
		int n;
		cin >> n;
		int *a = new int[n];
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		cout << min_subset_sum_diff(a, n) << endl;
	}
	return 0;
}
