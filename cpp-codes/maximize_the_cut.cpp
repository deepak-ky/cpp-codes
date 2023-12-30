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

int maximize_the_cut_segment(int n, int x, int y, int z)
{
	int dp[n + 1];
	memset(dp, -1, sizeof(dp));

	dp[0] = 0;

	for (int i = 1; i < n + 1; i++)
	{
		if ((i - x) >= 0 && dp[i - x] != -1)
		{
			dp[i] = max(dp[i], 1 + dp[i - x]);
		}

		if ((i - y) >= 0 && dp[i - y] != -1)
		{
			dp[i] = max(dp[i], 1 + dp[i - y]);
		}

		if ((i - z) >= 0 && dp[i - z] != -1)
		{
			dp[i] = max(dp[i], 1 + dp[i - z]);
		}
	}


	return dp[n];
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

		int x, y, z;
		cin >> x >> y >> z;

		cout << maximize_the_cut_segment(n, x, y, z);
	}
	return 0;
}
