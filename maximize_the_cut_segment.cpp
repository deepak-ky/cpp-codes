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

int maximum_price_segments(int n, int * len)
{
	int dp[n + 1];
	memset(dp , -1 , sizeof(dp));

	dp[0] = 0;

	for (int i = 1; i <= n; i++)
	{
		int ans = 0;
		for (int j = 0; j < 3; j++)
		{
			if ( i >= len[j])
			{
				if (dp[i - len[j]] != 0 || (i - len[j] == 0))
				{
					ans = max(ans, 1 + dp[ i - len[j]]);
				}
			}

		}
		dp[i] = ans;
	}

	return dp[n];
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

	test
	{
		int n;
		cin >> n;
		int len[3];
		for (int i = 0; i < 3; i++)
		{
			cin >> len[i];
		}
		cout << maximum_price_segments(n, len);
	}
	return 0;
}
