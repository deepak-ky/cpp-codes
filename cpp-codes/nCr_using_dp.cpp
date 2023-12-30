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

int n_C_r(int n, int r)
{
	int dp[n + 1][r + 1];
	memset(dp, -1, sizeof(dp));


	for (int i = 0; i < n + 1; i++)
	{
		for (int j = 0; j < r + 1; j++)
		{

			if (j > i)
			{
				continue;
			}

			else if (i == 0)
			{
				continue;
			}

			else if (j == 0)
			{
				dp[i][j] = 1;
			}

			else if (i == j)
			{
				dp[i][j] = 1;
			}

			else
			{

				dp[i][j] = (dp[i - 1][j - 1] % mod + dp[i - 1][j] % mod) % mod;
			}

		}
	}

	return (dp[n][r] + mod) % mod;
}

int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{
		int n;
		int r;
		cin >> n >> r;

		cout << n_C_r(n, r);
	}
	return 0;
}
