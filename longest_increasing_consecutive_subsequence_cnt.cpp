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

void display_dp(int *dp, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (dp[i] == INT_MIN)
		{
			cout << "MIN" << " ";
		}
		else if (dp[i] == INT_MAX)
		{
			cout << "MAX" << " ";
		}
		else cout << dp[i] << " ";
	}

	cout << endl;
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


		int dp[n + 1];

		dp[0] = INT_MIN;

		for (int i = 1; i < n + 1; i++)
		{
			dp[i] = INT_MAX;
		}

		display_dp(dp, n + 1);


		for (int i = 0; i < n; i++)
		{
			int num = a[i];

			wer(num);

			auto up = lower_bound(dp, dp + n + 1, num);

			int index = up - dp;

			wer(index);

			dp[index] = a[i];

			display_dp(dp, n + 1);
		}




		for (int i = (n); i >= 0; i--)
		{
			if (dp[i] !=  INT_MAX)
			{
				cout << i << endl;
				break;
			}
		}

	}
	return 0;
}
