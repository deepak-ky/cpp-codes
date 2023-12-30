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

	test
	{
		string s;
		cin >> s;
		unordered_map<char, int> mp;
		for (int i = 0; i < s.length(); i++)
		{
			mp[s[i]]++;

		}
		char ch;
		int max_frequency = 0;
		for (auto x : mp)
		{
			//cout << x.first << x.second;
			if (x.second > max_frequency)
			{
				max_frequency = x.second;
				ch = x.first;
			}
		}
		char ch1;
		if (ch == 'R') ch1 = 'P';
		else if (ch == 'P') ch1 = 'S';
		else if (ch == 'S') ch1 = 'R';
		for (int i = 0; i < s.length(); i++)
		{
			cout << ch1;
		}

		cout << endl;
	}

	return 0;
}
