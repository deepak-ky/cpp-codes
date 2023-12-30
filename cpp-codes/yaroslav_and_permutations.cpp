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
bool compare(pair<int, int> p1, pair<int, int> p2)
{
	return p1.second >= p2.second;
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
	int w = (n + 1) / 2;
	int a[n];
	unordered_map<int, int> mp;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		mp[a[i]]++;
	}
	vector<int> v;
	int flag = 1;
	for (auto x : mp)
	{
		if ((x.second) > w)
		{
			cout << "NO";
			flag = 0;
			break;
		}
	}
	if (flag)
	{
		cout << "YES";
	}


	return 0;
}
