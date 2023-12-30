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
	test
	{
		int n, m;
		cin >> n >> m;
		int w = (m / 2) * n;
		if (m == 1)
		{
			if (n % 2 == 0)
			{
				cout << n / 2 << endl;
			}
			else cout << (n / 2) + 1 << endl;
		}
		else
		{
			if (m % 2 == 0)
			{
				cout << w << endl;
			}
			else
			{
				int j;
				if (n % 2 == 0)
				{
					j = n / 2;
				}
				else j = n / 2 + 1;
				cout << w + j << endl;
			}
		}
	}
	return 0;
}
