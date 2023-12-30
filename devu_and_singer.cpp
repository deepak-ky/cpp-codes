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
	int n, d;
	cin >> n >> d;
	int no_of_breaks = n - 1;
	int a[n];
	asdf(a, n);
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += a[i];
	}
	int sum1 = 0;
	sum1 += (n - 1) * 10;
	sum += sum1;
	if (sum > d)
	{
		cout << -1;
	}
	else
	{
		cout << (abs(sum - d) + sum1) / 5;
	}
	return 0;
}
