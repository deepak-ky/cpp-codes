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
	vector<char> v;
	for (int i = 0; i < (s.length()); i++)
	{
		if (s[i] != '+')
		{
			v.push_back(s[i]);
		}
	}

	sort(v.begin(), v.end());
	cout  << v[0];
	char d = '+';
	for (int i = 1; i < v.size(); i++)
	{
		cout << d;
		cout << v[i];
	}
	return 0;
}