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

int min_attempts_required(int eggs , int floors)
{
	if (eggs == 0)
	{
		return -1;
	}

	if (floors == 0)
	{
		return 0;
	}

	if (eggs == 1)
	{
		return floors;
	}

	if (floors == 1)
	{
		return 1;
	}



	int n = eggs + 1;
	int m = floors + 1;


	int dp[n][m];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (i == 0)
			{
				dp[i][j] = -1;
			}
			else if (i == 1)
			{
				dp[i][j] = j;
			}
			else if (j == 0)
			{
				dp[i][j] = 0;
			}
			else if (j == 1)
			{
				dp[i][j] = 1;
			}
			else
			{
				int ans = INT_MAX;
				for (int k = 0; k < j; k++)
				{
					int m1 = max(dp[i - 1][k], dp[i][j - k - 1]);
					ans = min(ans, m1);
				}

				dp[i][j] = ans + 1;
			}
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

	return dp[eggs][floors];
}

int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{

		int eggs;
		int floors;

		cin >> eggs;

		cin >> floors;


		cout << min_attempts_required(eggs, floors);

	}
	return 0;
}
