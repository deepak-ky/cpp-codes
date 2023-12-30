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
int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a % b);
}
int lcm(int a, int b)
{
	return (a * b) / gcd(a, b);
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
	int a[n];
	asdf(a, n);
	int lcmm = lcm(a[0], a[1]);
	int gcdd = lcmm;
	for (int i = 0; i < n; i++)
	{
		int k = i + 1;
		if (i == 0)
		{
			k = i + 2;
		}
		for (int j = k; j < n; j++)
		{
			int lcdd = lcm(a[i], a[j]);
			gcdd = gcd(gcdd, lcdd);
		}
	}
	cout << gcdd;
	return 0;
}
