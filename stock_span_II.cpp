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
	int a[n];
	asdf(a, n);
	int inc[n] = {};
	inc[0] = 1;
	stack<int> s;
	for (int i = 0; i < n; i++)
	{
		while (s.empty() == false && (a[i] >= a[s.top()]))
		{
			s.pop();
		}
		int bet = s.empty() ? 0 : s.top();
		int span;
		if (bet == 0)
		{
			span = (i + 1) - bet;
		}
		else
		{
			span = (i ) - bet;

		}
		inc[i] = span;
		s.push(i);
	}
	for (auto x : inc)
	{cout << x << " ";}
	cout << "END";
	return 0;
}
