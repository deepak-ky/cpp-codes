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
	int n, x;
	cin >> n >> x;
	int sum = 0;
	int w = 1;
	for (int i = 0; i < n; i++)
	{
		int l, r;
		cin >> l >> r;
		if ( i == 0)
			sum += ((l - 1) % x);
		else sum += ((l - (w + 1)) % x);
		sum += (r - l) + 1;
		w = r;
	}
	cout << sum << endl;

	return 0;
}
