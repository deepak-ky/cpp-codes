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
class custom_compare
{
public:
	bool operator()(pair<int, int> p1, pair<int, int> p2)
	{
		if (p1.second != p2.second)
		{
			if (p1.second > p2.second)
			{
				return true;
			}
			else return false;
		}
		else
		{
			if (p1.first < p2.first)
			{
				return true;
			}
			else return false;
		}
	}
};
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
		set<pair<int, int>, custom_compare > s;
		map<int, int> mp;
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			int w;
			cin >> w;
			mp[w]++;
		}
		for (auto x : mp)
		{
			s.insert({x.first, x.second});
		}
		for (auto x : s)
		{
			while (x.second--)
				cout << x.first << " ";
		}
		cout << endl;
	}
	return 0;
}
