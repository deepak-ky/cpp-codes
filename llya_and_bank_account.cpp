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
	if (n > 0)
	{
		cout << n;
	}
	else if (n == 0)
	{
		cout << 0;
	}
	else
	{
		n = abs(n);
		//wer(n);
		int r = n % 10;

		//wer(r);
		n = n / 10;
		//wer(n);
		int r1 = n % 10;
		//wer(n);
		//wer(r1);
		n = n / 10;
		int s = min(r, r1);
		int w = n * 10 + s;
		cout << -w;
	}

	return 0;
}
