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
//ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	test
	{
		int a, b, c, d, e;
		cin >> a >> b >> c >> d >> e;
		int ob = b;
		ob = max( ob - e , d);
		int oa = a;
		oa = max(oa - e , c);
		if ( oa >= ob )
		{
			int oob = b;
			b = max( b - e , d);
			e = e - (oob - b);
			a = max (a - e , c);
			cout << a*b << endl;
		}
		else
		{
			int ooa = a;
			a = max( a - e , c);
			e = e - (ooa - a);
			b = max (b - e , d);
			cout << a*b << endl;
		}
	}
	return 0;
}
