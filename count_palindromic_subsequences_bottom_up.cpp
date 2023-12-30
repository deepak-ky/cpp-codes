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

int palindromic_subsequences(string a)
{
	int n = a.length();
	int dp[n][n];

	memset(dp, -1, sizeof(dp));

	for (int i = 0; i < n; i++)
	{
		dp[i][i] = 1;
	}

	for (int i = 1; i < n; i++)
	{
		if (a[i - 1] == a[i])
		{
			dp[i - 1][i] = 3;
		}
		else dp[i - 1][i] = 2;
	}

	for (int gap = 2; gap < n; gap++)
	{
		int i = 0;
		for (int j = gap; j < n; j++)
		{
			if (a[i] == a[j])
			{
				dp[i][j] = dp[i][j - 1] % mod + dp[i + 1][j] % mod + 1;
				dp[i][j] %= mod;
			}
			else
			{
				dp[i][j] = dp[i][j - 1] % mod + dp[i + 1][j] % mod - dp[i + 1][j - 1] % mod;
				dp[i][j] %= mod;
			}
			i++;
		}
	}


	return dp[0][n - 1] % mod;
}

int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{
		string a;
		cin >> a;

		cout << palindromic_subsequences(a);

	}
	return 0;
}
