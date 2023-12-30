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
int binary_string(int n)
{
	int a[n], b[n];
	a[0] = 1;
	b[0] = 1;
	for (int i = 1; i < n; i++)
	{
		a[i] = a[i - 1] + b[i - 1];
		b[i] = a[i - 1];
	}
	return (a[n - 1] + b[n - 1]);
}
int32_t main()
{

#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	test
	{
		int n;
		cin >> n;
		cout << binary_string(n) << endl;
	}
	return 0;
}
