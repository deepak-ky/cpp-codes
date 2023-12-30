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
	int k;
	cin >> n >> k;
	int a[n];
	map<int, int, greater<int>> mp;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		mp[a[i]] = i;

	}
	for (int i = 0; i < n && k > 0; i++)
	{
		//out(a, n);
		if (a[i] != (n - i))
		{
			int index = mp[n - i];
			mp[a[i]] = index;
			mp[n - i] = i;
			swap(a[i], a[index]);
			k--;

		}
		//out(a, n);
	}
	for (auto x : a)
	{
		cout << x << " ";
	}

	return 0;
}