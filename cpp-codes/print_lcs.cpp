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

char * print_lcs(string a, string b, int n, int m)
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
	int index = dp[n][m];
	char * lcs = new char[index + 1];
	lcs[index] = '\0';

	int i = n;
	int j = m;
	index--;
	while (i > 0 && j > 0)
	{
		if (a[i - 1] == b[j - 1])
		{
			lcs[index] = a[i - 1];
			index--;
			i--;
			j--;
		}
		else if (dp[i - 1][j] >= dp[i][j - 1])
		{
			i--;
		}
		else {
			j--;
		}

	}


	return lcs;

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
	//int n, m;
	//cin >> n >> m;
	string a; string b;
	cin >> a >> b;
	char * ans = print_lcs(a, b, a.length(), b.length());
	for (int i = 0; ans[i] != '\0'; i++)
	{
		cout << ans[i];
	}
	return 0;
}
