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
//we need not check for length we just need to check whether it is present or not
bool is_present(string str, int s, int e, int j)
{
	for (int i = s; i < e; i++)
	{
		if (str[i] == str[j])
		{
			return true;
		}
	}
	return false;
}
bool check_for_subsequence(string str, int s, int e, int len)
{
	int i = s + 1;
	int j = e + 1;
	while ((j < len) && (i < e))
	{
		if (is_present(str, i, e, j))
		{
			return true;
		}
		j++;
	}
	return false;
}
int32_t main()
{

#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	string s;
	cin >> s;
	int len = s.length();
	unordered_map<char, int> mp;
	int flag = 0;
	for (int i = 0; i < len; i++)
	{
		if (mp[s[i]] != 0)
		{
			if (check_for_subsequence(s, (mp[s[i]] - 1), i, len))
			{
				flag = 1;
				break;
			}
			else mp[s[i]] = i + 1;
		}
		else
		{
			mp[s[i]] = i + 1;
		}
	}
	for (auto x : mp)
	{
		cout << x.first << " " << x.second;
	}
	if (flag)
	{
		cout << "true";
	}
	else cout << "false";
	return 0;
}
