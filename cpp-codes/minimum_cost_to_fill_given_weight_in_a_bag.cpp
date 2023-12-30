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

int find_min_cost(int *a, int n, int w)
{
	int dp[w + 1];


	memset(dp, -1, sizeof(dp));
	dp[0] = 0;

	for (int i = 1; i <= min(w, n); i++)
	{
		dp[i] = INT_MAX;

		for (int j = 1; j <= i; j++)
		{
			if (a[j - 1] != -1 && dp[i - j] != -1)
			{
				dp[i] = min(dp[i], a[j - 1] + dp[i - j]);
			}
		}

		if (dp[i] == INT_MAX)
		{
			dp[i] = -1;
		}
	}


	for (int i = n + 1; i < w + 1; i++)
	{
		dp[i] = INT_MAX;

		for (int j = 1; j <= n; j++)
		{
			if (a[j - 1] != -1 && dp[i - j] != -1)
			{
				dp[i] = min(dp[i], a[j - 1] + dp[i - j]);
			}
		}

		if (dp[i] == INT_MAX)
		{
			dp[i] = -1;
		}

	}

	out(dp, w + 1);

	return dp[w];
}

int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{

		int n;
		cin >> n;
		int *a = new int[n];
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}

		int w;
		cin >> w;

		cout << find_min_cost(a, n, w);

	}
	return 0;
}
