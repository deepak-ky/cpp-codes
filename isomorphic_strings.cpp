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

bool is_isomorphic(string x, string y)
{

	if (x.length() != y.length())
	{
		return false;
	}
	unordered_map<char, char> mp;
	vector<char> char_used;

	for (int i = 0; i < x.length(); i++)
	{
		char ch = y[i];
		if (mp.find(ch) != mp.end())
		{
			//not a new char
			char should_match = mp[ch];
			if (x[i] != should_match)
			{
				return false;
			}
		}
		else
		{

			//a new character
			//can match to any character until and unless , the correspondent is not present in the
			//char used vector
			char should_match = x[i];
			if (find(char_used.begin(), char_used.end(), should_match) != char_used.end())
			{
				return false;
			}
			else
			{
				mp[y[i]] = should_match;
				char_used.pb(x[i]);
			}
		}
	}
	return true;
}


int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{

		string x, y;
		cin >> x >> y;

		if (is_isomorphic(x, y))
		{
			yes;
		}
		else no;

	}
	return 0;
}
