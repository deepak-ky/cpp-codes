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

		vector<pair<int, int>> v;
		int n;
		cin >> n;

		for (int i = 0; i < n; i++)
		{
			int a, b;
			cin >> a >> b;
			v.push_back({a, b});
		}

		sort(v.begin(), v.end());

		for (auto x : v)
		{
			cout << x.first << " " << x.second << endl;
		}

		int dp[n];

		dp[0] = 1;
		int ans = 1;

		for (int i = 1; i < n; i++)
		{
			int w = 0;

			for (int j = 0; j < i; j++)
			{
				if (v[j].second < v[i].first)
				{
					w = max(w, dp[j]);
				}
			}

			dp[i] = w + 1;
			ans = max(ans, dp[i]);
		}

		cout << ans << endl;





	}
	return 0;
}
