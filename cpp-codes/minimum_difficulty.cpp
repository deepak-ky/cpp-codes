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
int find_max_diff(vector<int> v)
{
	int m = INT_MIN;
	for (int i = 1; i < v.size(); i++)
	{
		int w = v[i] - v[i - 1];
		m = max(m, w);
	}
	return m;
}
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
	vector<int> v;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		v.push_back(x);
	}
	int min_diff = INT_MAX;
	for (int i = 1; i < (n - 1); i++)
	{
		int w = v[i];
		v.erase(v.begin() + i);
		int max_diff = find_max_diff(v);
		min_diff = min(min_diff, max_diff);
		v.insert(v.begin() + i, w);

	}
	cout << min_diff;
	// for (auto x : v)
	// {

	// 	cout << x << " ";
	// }

	return 0;
}
