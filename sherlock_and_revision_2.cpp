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
	string a;
	cin >> a;
	unordered_map<char, int> mp;
	for (int i = 0; i < a.length(); i++)
	{
		mp[a[i]]++;
	}
	set<int> s;
	string ans = "NO";
	for (auto x : mp)
	{
		s.insert(x.second);
	}
	if (s.size() == 1)
	{
		ans = "YES";
	}
	else
	{
		s.clear();
		for (auto x : mp)
		{
			cout << endl;
			mp[x.first]--;
			for (auto y : mp)
			{
				if (y.second > 0)
				{
					s.insert(y.second);
				}

			}
			cout << endl;
			if (s.size() == 1)
			{
				ans = "YES";
			}
			s.clear();
			mp[x.first]++;
		}
	}
	cout << ans << endl;

	return 0;
}
