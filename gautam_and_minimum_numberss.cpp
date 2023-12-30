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
	set<int> s;
	vector<int> v;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		s.insert(x);
		v.push_back(x);
	}
	while ((s.size() != 1))
	{
		int t; int d;
		cin >> t; cin >> d;
		vector<int> v1(v);
		sort(v1.begin(), v1.end());
		auto it = s.begin();
		auto it_1 = v.begin();
		int a = *it;
		int a1 = *it_1;
		s.erase(it);
		v.erase(*it_1);

		auto it1 = s.begin();
		int b = *it1;
		s.erase(it1);
		if ( t == 1)
		{
			s.insert(a + b + d);
		}
		else
		{
			s.insert(((a - b) + d));
		}
	}
	auto it = s.begin();
	cout << *it;






	return 0;
}
