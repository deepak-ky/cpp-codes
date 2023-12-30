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
		string s;
		cin >> s;
		int k;
		cin >> k;
		int n = s.length();
		int *dp = new int[n + 1];
		for (int i = 0; i <= n; i++)
		{
			dp[i] = 0;
		}
		dp[n] = 1;
		for (int i = n - 1; i >= 0; i--)
		{
			int sum = 0;
			for (int j = i; j < n; j++)
			{
				sum = sum * 10 + (s[j] - '0');
				if (sum == 0 || sum > k)
				{
					break;
				}
				else
				{
					dp[i] += dp[j + 1];
					dp[i] %= mod;
				}
			}
		}
		cout << dp[0] << endl;
	}
	return 0;
}
