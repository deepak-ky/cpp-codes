#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int                          long long
#define varname(name)                #name
#define mod                          1000000007
#define wer(x)                       cout<<"\n"<<varname(x)<<" here : \n"<<x
#define test                         int t; cin>>t; while(t--)
#define asdf(a,n)                    for(int i=0;i<n;i++)  cin>>a[i]
#define out(a,n)                     cout<<"\n"<<varname(a)<<" here is : \n";for(int i=0;i<n;i++) cout<<a[i]<<" "; cout<<endl
#define pb                           push_back

void fill_map(int n, unordered_map<int, int> &mp)
{
	bitset<32> b(n);
	for (int i = 31; i >= 0; i--)
	{
		if (b[i] == 1)
		{
			mp[i]++;
			break;
		}
	}
}

int32_t main()
{
//ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	test
	{
		unordered_map<int, int> mp;
		int n;
		cin >> n;
		int *a = new int[n];
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			fill_map(a[i], mp);
		}
		int ans = 0;
		for (auto x : mp)
		{
			if (x.second > 1)
			{
				int n = x.second;
				ans += (n * (n - 1)) / 2;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
