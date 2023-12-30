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

		unordered_map<int, int> mp;
		int *dp = new int[n] {0};
		int ans = 0;
		for (int i = 0; i < n; i++)
		{
			int c = a[i];
			auto it = mp.find(c - 1);
			if (it != mp.end())
			{
				//c-1 is present and is present before the current i
				int ind = mp[c - 1];
				dp[i] = 1 + dp[ind];
				ans = max(ans, dp[i]);
			}
			else dp[i] = 1;

			mp[c] = i;
		}
		cout << ans << endl;



	}
	return 0;
}
