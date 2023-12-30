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
#define MAX 1000005
int dp[MAX];
int dp1[MAX];
int32_t main()
{
//ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	int t, n;
	cin >> t >> n;

	dp[0] = 0;
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 0;
	dp[4] = 1;
	dp[5] = 1;
	for (int i = 6; i < n + 1; i++)
	{

		dp[i] = (dp[i - 2] + dp[i - 5]) % mod;
	}

	while (t--)
	{
		int curr , k;
		cin >> curr >> k;
		if ((curr < k) || (curr == 2) || (curr == 5))
		{
			cout << dp[curr] << endl;
		}
		else if (curr == k)
		{
			cout << (dp[curr] + 1) % mod << endl;
		}
		else if (curr > k) // the step of k can influence me
		{
			for (int i = 0; i <= k ; i++)
			{
				dp1[i] = dp[i];
			}
			dp1[k] = (dp1[k] + 1 ) % mod;
			for (int i = k + 1; i <= curr; i++)
			{
				dp1[i] = (dp1[i - 2] % mod + dp1[i - 5] % mod + dp1[i - k] % mod) % mod;
			}
			cout << dp1[curr] << endl;
		}
	}
	return 0;
}
