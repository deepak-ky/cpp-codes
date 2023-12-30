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

int lrs_length(string a, string b, int n, int m)
{
	int  dp[n + 1][m + 1];
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			if (i == 0 || j == 0)
			{
				dp[i][j] = 0;
			}
			else
			{
				if (a[i - 1] == b[j - 1] && i != j)
				{
					dp[i][j] = 1 + dp[i - 1][j - 1];
				}
				else dp[i][j] = max(dp[i - 1][j] , dp[i][j - 1]);
			}
		}
	}
	return dp[n][m];
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
	//int string_len;
	//cin >> string_len;
	string a;
	cin >> a;
	cout << lrs_length(a, a, a.length(), a.length());
	return 0;
}
