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

		int n;
		cin >> n;
		int *a = new int[n];
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}

		int diff;

		cin >> diff;



		// N^2 approach --> X

		// Instead of finding out ki , mere se pahle small element present hain ki nahi
		// I can just have an unordered_map, that will tell me , ki agar present hain
		// toh kahan hain , and agar more than one occurence hain , toh kaunse index wale ki zyada hain

		int dp[n];

		dp[0] = 1;

		unordered_map<int, int> mp;

		mp[a[0]] = 0;

		for (int i = 1; i < n; i++)
		{
			int small = a[i] - diff;

			if (mp.find(small) == mp.end())
			{
				dp[i] = 1;
			}
			else
			{
				int index = mp[small];
				dp[i] = dp[index] + 1;
			}

			if (mp.find(a[i]) == mp.end())
			{
				mp[a[i]] = i;
			}
			else
			{
				int index = mp[a[i]];
				if (dp[i] > dp[index])
				{
					mp[a[i]] = i;
				}
			}
		}

		out(dp, n);

		int ans = 1;

		for (int i = 0; i < n; i++)
		{
			ans = max(ans, dp[i]);
		}

		cout << ans;

	}
	return 0;
}
