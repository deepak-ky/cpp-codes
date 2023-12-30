#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int                          long long
#define varname(name)                #name
#define mod                          1000000007
#define wer(x)                       cout<<"\n"<<varname(x)<<" here : "<<x<<"\n"
#define asdf(a,n)                    for(int i=0;i<n;i++)  cin>>a[i]
#define out(a,n)                     cout<<"\n"<<varname(a)<<" here is : ";for(int i=0;i<n;i++) cout<<a[i]<<" "; cout<<endl
void display_map(map<int, int> mp)
{
	for (auto x : mp)
	{
		cout << x.first << "-->" << x.second << endl;
	}
}
int32_t main()
{
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	int a[n];
	asdf(a, n);
	map<int, int> mp;
	set<pair<int, int> > s;
	for (int i = 0; i < n; ++i)
	{
		mp[a[i]]++;
	}
	int cnt = 0;
	while (cnt < (n))
	{
		auto it = mp.begin();
		int w1 = (*it).first;
		cout << w1 << " ";
		cnt++;
		wer(cnt);
		if (cnt == n) break;
		//int w = (*it).second--;
		if (mp[w1] - 1 == 0)
		{
			mp.erase(w1);
		}
		else mp[w1]--;
		auto it1 = mp.upper_bound(w1);
		if (it1 != mp.end())
		{
			int w3 = (*it1).first;
			cout << w3 << " ";
			cnt++;
			wer(cnt);
			if (cnt == n) break;
			//int w4 = (*it1).second--;
			if (mp[w3] - 1 == 0)
			{
				mp.erase(w3);
			}
			else mp[w3]--;
		}
		else
		{
			auto it2 = mp.begin();
			int w5 = (*it2).first;
			cout << w5 << " ";
			cnt++;
			wer(cnt);
			if (cnt == n) break;
			//int w6 = (*it2).second--;
			if (mp[w5] - 1 == 0)
			{
				mp.erase(w5);
			} else mp[w5]--;
		}
		cout << endl;
		display_map(mp);
	}
	return 0;
}
