#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int                          long long
#define varname(name)                #name
#define mod                          1000000007
#define wer(x)                       cout<<"\n"<<varname(x)<<" here : "<<x<<"\n"
#define asdf(a,n)                    for(int i=0;i<n;i++)  cin>>a[i]
#define out(a,n)                     cout<<"\n"<<varname(a)<<" here is : \n";for(int i=0;i<n;i++) cout<<a[i]<<" "; cout<<endl
#define pb                           push_back
#define yes                          cout << "YES" << endl;
#define no                           cout << "NO"  << endl;
#define f                            first
#define se                            second

void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
}

bool is_valid(string s, string pattern)
{
	int n = pattern.length();
	int m = s.length();
	bool dp[n + 1][m + 1];
	dp[n][m] = true;
	for (int i = m - 1; i >= 0; i--)
	{
		dp[n][i] = false;
	}
	for (int i = n - 1; i >= 0; i--)
	{
		if (pattern[i] == '*')
		{
			dp[i][m] = dp[i + 1][m];
		}
		else dp[i][m] = false;
	}

	for (int i = (n - 1); i >= 0; i--)
	{
		for (int j = (m - 1); j >= 0; j--)
		{
			if (pattern[i] == '?')
			{
				dp[i][j] = dp[i + 1][j + 1];
			}
			else if (pattern[i] == '*')
			{
				dp[i][j] = (dp[i + 1][j] | dp[i][j + 1]);
			}
			else
			{
				if (pattern[i] == s[j])
				{
					dp[i][j] = dp[i + 1][j + 1];
				}
				else
				{
					dp[i][j] = false;
				}
			}
		}
	}


	/*	for (int i = 0; i < (n + 1); i++)
		{
			for (int j = 0; j < (m + 1); j++)
			{
				cout << dp[i][j] << " ";
			}
			cout << endl;
		}*/


	return dp[0][0];
}

int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{

		string s;
		cin >> s;
		string pattern;
		cin >> pattern;
		if (is_valid(s, pattern))
		{
			yes;
		}
		else no;

	}
	return 0;
}
