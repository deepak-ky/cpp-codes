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



int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;

		int dp[n][m];

		dp[0][0] = 3;

		for (int i = 1; i < m; i++)
		{
			dp[0][i] = (dp[0][i - 1] * 2) % mod;
		}

		for (int i = 1; i < n; i++)
		{
			dp[i][0] = (dp[i - 1][0] * 2) % mod;
		}

		for (int i = 1; i < n; i++)
		{
			for (int j = 1; j < m; j++)
			{
				dp[i][j] = (max(dp[i - 1][j], dp[i][j - 1]) * 3) % mod;
			}
		}

		// for (int i = 0; i < n; i++)
		// {
		// 	for (int j = 0; j < m; j++)
		// 	{
		// 		cout << dp[i][j] << " ";
		// 	}
		// 	cout << endl;
		// }

		cout << dp[n - 1][m - 1];
	}
	return 0;
}
