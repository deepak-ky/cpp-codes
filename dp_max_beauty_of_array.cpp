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
int max_beauty(int idx, int state, int *a, int n, int dp[][3], int x)
{
	if (idx == n)
	{
		return 0;
	}
	if (dp[idx][state] != -1)
	{
		return dp[idx][state];
	}
	int temp_ans = INT_MIN;
	if (state == 0)
	{
		temp_ans = max(temp_ans, a[idx] + max_beauty(idx + 1, 0, a, n, dp, x));
		temp_ans = max(temp_ans, (a[idx] * x) + max_beauty(idx + 1, 1, a, n, dp, x));
	}
	else if (state == 1)
	{
		temp_ans = max(temp_ans, (a[idx] * x) + max_beauty(idx + 1, 1, a, n, dp, x));
		temp_ans = max(temp_ans, (a[idx]) + max_beauty(idx + 1, 2, a, n, dp, x));
	}
	else if (state == 2)
	{
		temp_ans = max(temp_ans, a[idx] + max_beauty(idx + 1, 2, a, n, dp, x));
	}
	return dp[idx][state] = temp_ans;
}
int32_t main()
{

#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	int n, x;
	cin >> n >> x;
	int a[n];
	asdf(a, n);
	int dp[n][3];
	memset(dp, -1, sizeof dp);
	int ans = INT_MIN;
	for (int i = 0; i < n; i++)
	{
		ans = max(ans, max_beauty(i, 0, a, n, dp, x));
	}
	if (ans > 0)
	{
		cout << ans;
	}
	else cout << 0;
	return 0;
}
