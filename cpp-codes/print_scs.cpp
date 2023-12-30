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

string print_scs(string a, string b, int n, int m)
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
				if (a[i - 1] == b[j - 1])
				{
					dp[i][j] = 1 + dp[i - 1][j - 1];
				}
				else dp[i][j] = max(dp[i - 1][j] , dp[i][j - 1]);
			}
		}
	}
	string scs;
	int i = n;
	int j = m;
	while (i > 0 && j > 0)
	{
		if (a[i - 1] == b[j - 1])
		{
			scs += a[i - 1];
			i--;
			j--;
		}
		else if (dp[i][j - 1] >= dp[i - 1][j])
		{
			scs += b[j - 1];
			j--;
		}
		else
		{
			scs += a[i - 1];
			i--;
		}
	}
	while (i > 0)
	{
		scs += a[i - 1];
		i--;
	}
	while (j > 0)
	{
		scs += b[j - 1];
		j--;
	}

	reverse(scs.begin(), scs.end());
	return scs;
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
	string a, b;
	cin >> a >> b;
	cout << print_scs(a, b, a.length(), b.length());
	return 0;
}
