#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int                          long long
#define varname(name)                #name
#define mod                          1000000007
#define wer(x)                       cout<<"\n"<<varname(x)<<" here : "<<x
#define fast                         ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
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
	fast;
	int r1, r2, c1, c2, d1, d2;
	cin >> r1 >> r2 >> c1 >> c2 >> d1 >> d2;
	if ( (r1 == c1) || (r1 == c2) || (r1 == d1) || (r1 == d2) || (r2 == c1) || (r2 == c2) || (r2 == d1) || (r2 == d2) || (c1 == d1) || (c1 == d2) || (c2 == d1) || (c2 == d2) )
	{
		cout << -1;

	}
	else
	{

		int x = r1 - (c2 - d1);
		if ((x & 1))
		{	cout << "fe";
			cout << -1;
		}
		else
		{
			x /= 2;
			int w = r1 - x;
			int w1 = c1 - x;
			int w2 = d1 - x;

			if ((x == 0) || (w == 0) || (w1 == 0) || (w2 == 0) || (x >= 10) || (w >= 10) || (w1 >= 10) || (w2 >= 10) || ((w1 + w2) != r2) || ((w2 + w) != c2) || ((w1 + w) != d2))
			{

				cout << -1;
			}
			else
			{
				cout << x << " " << r1 - x;
				cout << endl;
				cout << c1 - x << " " << d1 - x;

			}
		}
	}


	return 0;
}
