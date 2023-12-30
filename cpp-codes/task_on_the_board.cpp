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
int cal_value(string s, int i)
{
	int val = 0;
	int ch = s[i];
	for (int j = 0; j < s.length(); j++)
	{
		if (s[j] > s[i])
		{
			val += abs(i - j);
		}
	}
	return val;
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
	map<char, int> value;
	map<char, int> freq;
	for (int i = 0; i < s.length(); i++)
	{
		int w = cal_value(s, i);
		wer(w);
	}

	return 0;
}
