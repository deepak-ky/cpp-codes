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
	if (n & 1)
	{
		int m;
		cin >> m;
		int w = (n / 2 + 1);
		if (m <= w)
		{
			cout << (m * 2) - 1;
		}
		else cout << (m - w) * 2;
	}
	else
	{
		int m;
		cin >> m;
		int w = (n / 2);
		if (m <= w)
		{
			cout << (m * 2) - 1;
		}
		else cout << (m - w) * 2;

	}
	return 0;
}
