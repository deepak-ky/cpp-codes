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

int lis(int *a, int n)
{
	int dp[n];
	for (int i = 0; i < n; i++)
	{
		dp[i] = 1;
	}
	int ans = 1;
	for (int i = 1; i < n; i++)
	{
		int local_max = 0;
		for (int j = 0; j < i; j++)
		{
			if (a[j] <= a[i])
			{
				local_max = max(local_max, dp[j]);
			}
		}
		dp[i] += local_max;
		ans = max(ans, dp[i]);
	}
	out(dp, n);
	return ans;
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
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	cout << lis(a, n);
	return 0;
}
