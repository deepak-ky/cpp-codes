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

#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	string s;
	cin >> s;

	for (int i = 0; i < s.length(); i++)
	{
		s[i] = tolower(s[i]);
	}
	vector<char> v;
	for (int i = 0; i < s.length(); i++)
	{
		v.push_back(s[i]);
	}
	//v[s.length()] = '\0';
	int i = 0;
	while (i < v.size())
	{
		if (v[i] == 'a' || v[i] == 'e' || v[i] == 'i' || v[i] == 'o' || v[i] == 'u' || v[i] == 'y')
		{	v.erase(v.begin() + i);
			i = i - 1;
		}
		else {i++;}
	}
	char c = '.';
	// for (int i = 0; i < v.size(); i = i + 2)
	// {
	// 	v.insert(v.begin() + i, c);
	// }

	for (auto x : v)
	{
		cout << c;
		cout << x;
	}
	return 0;
}
