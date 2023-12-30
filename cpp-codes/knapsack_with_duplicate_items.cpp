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



int  maximum_value(int *val, int *wt, int n, int req_wt)
{
	int dp[req_wt + 1];
	dp[0] = 0;
	for (int i = 1; i <= req_wt; i++)
	{
		dp[i] = 0;
		for (int j = 0; j < n; j++)
		{
			if (wt[j] <= i)
			{
				dp[i] = max(dp[i] , dp[i - wt[j]] + val[j]);
			}
		}
	}

	return dp[req_wt];
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


		int w;
		cin >> w;


		int val[n];
		int wt[n];

		for (int i = 0; i < n; i++)
		{
			cin >> val[i];
		}

		for (int i = 0; i < n; i++)
		{
			cin >> wt[i];
		}

		cout << maximum_value(val, wt, n, w);

	}
	return 0;
}
