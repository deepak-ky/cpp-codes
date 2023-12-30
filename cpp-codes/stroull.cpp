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

unordered_map<string, int> mp;

int steps_to_zero(string s)
{
	if (s == "0")
	{
		return 0;
	}

	if (mp.find(s) != mp.end())
	{
		return mp[s];

	}
	string s1 = s;
	int n = s.length();

	if (s[n - 1] == '1')
	{
		s[n - 1] = '0';
		return mp[s1] = 1 + steps_to_zero(s);
	}
	else
	{
		s = s.substr(0, n - 1);
		return mp[s1] = 1 + steps_to_zero(s);
	}
}

int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{
		string s = "0000000000000000000000000000000000000000000000000000000";
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == '1')
			{
				s = s.substr(i, s.length() - i);
				break;
			}
		}

		cout << s << endl;

		cout << steps_to_zero(s);

	}
	return 0;
}
