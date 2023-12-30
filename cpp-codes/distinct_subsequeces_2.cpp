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


int distinct_sub(string a)
{
	int n = a.length();
	int dp[n + 1];
	unordered_map<char, int> mp;
	dp[0] = 1;
	for (int i = 1; i < n + 1; i++)
	{
		char ch = a[i - 1];

		dp[i] = (dp[i - 1] % mod * 2) % mod;

		if (mp.find(ch) != mp.end())
		{
			int y = mp[ch];
			int w = dp[y - 1] % mod;

			dp[i] = (dp[i] % mod - w % mod) % mod;
		}

		mp[ch] = i;
	}


	return dp[n] % mod;

}

int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{

		//find the count of all the distinct subsequences


		string a;
		cin >> a;


		cout << distinct_sub(a);

	}
	return 0;
}
