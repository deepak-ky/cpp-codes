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
	if (a == 0)
	{
		return b;
	}
	else return gcd(b % a, a);
}

int32_t main()
{

#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	int a, b;
	cin >> a >> b;
	if (a & 1)
	{
		a++;
	}
	if (a + 2 > b)
	{
		cout << -1;
	}
	else cout << a << " " << a + 1 << " " << a + 2;

	return 0;
}
