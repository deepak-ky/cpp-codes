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
	map<int, int> mp;
	int p;
	cin >> p;
	for (int i = 0; i < p; i++)
	{
		int x;
		cin >> x;
		mp[x]++;
	}
	int q;
	cin >> q;
	for (int i = 0; i < q; i++)
	{
		int x;
		cin >> x;
		mp[x]++;
	}
	if (mp.size() == n)
	{
		cout << "I become the guy.";
	}
	else cout << "Oh, my keyboard!";
	return 0;
}
