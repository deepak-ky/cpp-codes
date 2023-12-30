#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int                          long long
#define varname(name)                #name
#define mod                          1000000007
#define wer(x)                       cout<<"\n"<<varname(x)<<" here : "<<x
#define test                         int t; cin>>t; while(t--)
#define asdf(a,n)                    for(int i=0;i<n;i++)  cin>>a[i]
#define out(a,n)                     cout<<"\n"<<varname(a)<<" here is : ";for(int i=0;i<n;i++) cout<<a[i]<<" "; cout<<endl
int32_t main()
{
//ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	int n, k;
	cin >> n >> k;
	int *a = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	unordered_map<int, pair<int, int>> mp;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			mp[(a[i] + a[j])] = {i, j};
		}
	}
	int cnt = 0;
	for (auto x : mp)
	{
		if (mp.find(k - x.first) != mp.end())
		{
			pair<int, int> p1 = x.second;
			pair<int, int> p2 = mp[k - x.first];
			if ((p1.first != p2.second) && (p1.first != p2.first) && (p1.second != p2.second) && (p1.second != p2.first))
			{
				cout << a[p1.first] << " ";
				cout << a[p1.second] << " ";
				cout << a[p2.first] << " ";
				cout << a[p2.second] << " ";
				cout << endl;
			}
			x.second = { -1, -1};
			mp[k - x.first] = { -1, - 1};

		}
	}
	return 0;
}
