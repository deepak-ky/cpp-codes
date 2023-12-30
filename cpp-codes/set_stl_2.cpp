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
	set<pair<int, int> > s;
	s.insert(make_pair(5, 6));
	s.insert(make_pair(4, 6));
	s.insert(make_pair(7, 6));
	s.insert(make_pair(100, 6));
	s.insert(make_pair(2, 6));
	s.erase(s.find(make_pair(7, 6)));
	for (auto i : s)
	{
		cout << i.first << "," << i.second << endl;
	}
	auto w = s.upper_bound(make_pair(4, 7));
	cout << endl << w->first << "," << w->second;
}
