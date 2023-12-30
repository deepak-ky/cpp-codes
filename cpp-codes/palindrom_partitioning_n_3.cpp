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

int find_min_cuts(string s)
{
	int n = s.length();
	bool is_palin[n][n];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			is_palin[i][j] = false;
		}
	}

	for (int gap = 0; gap < n; gap++)
	{
		for (int i = 0, j = gap; j < n; i++, j++)
		{
			if (gap == 0)
			{
				is_palin[i][j] = true;
			}
			else if (gap == 1)
			{
				if (s[i] == s[j])
				{
					is_palin[i][j] = true;
				}
			}
			else
			{
				if (s[i] == s[j] && (is_palin[i + 1][j - 1] == true))
				{
					is_palin[i][j] = true;
				}
			}
		}
	}




	int dp[n][n];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			dp[i][j] = -1;
		}
	}

	for (int gap = 0; gap < n; gap++)
	{
		for (int i = 0, j = gap; j < n; i++, j++)
		{
			if (is_palin[i][j] == true)
			{
				dp[i][j] = 0;
			}
			else if (gap == 0)
			{
				dp[i][j] = 0;
			}
			else if (gap == 1)
			{
				if (s[i] == s[j])
				{
					dp[i][j] = 0;
				}
				else dp[i][j] = 1;
			}
			else
			{
				dp[i][j] = INT_MAX;

				for (int k = i; k < (j); k++)
				{
					int opt = dp[i][k] + dp[k + 1][j] + 1;
					dp[i][j] = min(opt, dp[i][j]);
				}
			}
		}
	}




	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}





	return dp[0][n - 1];
}

int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{
		string s = "abccbc";
		cout << find_min_cuts(s);

	}
	return 0;
}
