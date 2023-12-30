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
	int n;
	cin >> n;
	string s;
	string s1;
	int cnt1 = 0;
	int cnt2 = 0;
	for (int i = 0; i < 1; i++)
	{
		string w;
		cin >> w;
		s = w;
		cnt1++;
	}
	for (int i = 1; i < n; i++)
	{
		string w;
		cin >> w;
		if (w == s)
		{
			cnt1++;
		}
		else
		{
			s1 = w;
			cnt2++;
		}
	}
	if (cnt1 > cnt2) cout << s;
	else cout << s1;
	return 0;
}
