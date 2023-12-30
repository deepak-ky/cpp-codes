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
bool compare(int a, int b)
{
	return a > b;
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
		int w;
		cin >> w;
		v.push_back(w);
	}
	sort(v.begin(), v.end(), compare);
	int sum = 0;
	for (auto x : v)
	{
		sum = sum + x;
	}
	int sum1 = 0;
	for (int i = 0; i < v.size(); i++)
	{
		sum1 = sum1 + v[i];
		if (sum1 > (sum - sum1))
		{
			cout << i + 1 ; break;
		}
	}
	return 0;
}
