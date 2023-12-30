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

bool compare(string s1, string s2)
{
	int len1 = s1.length();
	int len2 = s2.length();
	if (len1 <= len2)
	{
		string w = s2.substr(0, len1);
		if (w == s1)
		{
			return false;
		}
		else
		{
			if (s1 < s2)
			{
				return true;
			}
			else return false;
		}
	}
	else
	{
		string w = s1.substr(0, len2);
		if (w == s2)
		{
			return true;
		}
		else
		{
			if (s1 < s2)
			{
				return true;
			}
			else return false;
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

	int n;
	cin >> n;
	vector<string> v;
	for (int i = 0; i < n; i++)
	{
		string w;
		cin >> w;
		v.push_back(w);
	}
	sort(v.begin(), v.end(), compare);
	for (auto x : v)
	{
		cout << x << " ";
	}
	return 0;
}
