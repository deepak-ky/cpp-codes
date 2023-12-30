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
#define se                           second

int zero = 0;

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


	int dp[n];

	dp[0] = 0;

	if (n >= 2)
	{
		if (s[0] == s[1])
		{
			dp[1] = 0;
		}
		else dp[1] = 1;
	}


	for (int i = 2; i < n; i++)
	{
		dp[i] = INT_MAX;
		for (int j = 0; j <= i; j++)
		{
			if (is_palin[j][i] == true)
			{
				if (j == 0)
				{

					dp[i] = min(dp[i], zero);
				}
				else
				{
					dp[i] = min(dp[i] , 1 + dp[j - 1]);
				}
			}
		}




	}


	out(dp, n);

	return dp[n - 1];
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
