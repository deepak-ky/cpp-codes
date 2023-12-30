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
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	int x_diff = abs(x1 - x2);
	int y_diff = abs(y1 - y2);
	if ( (x_diff != 0) && (y_diff != 0) && (x_diff != y_diff))
	{
		cout << -1;
	}
	else
	{
		if (x_diff == 0)
		{
			int x3 = x1 + y_diff;
			int x4 = x2 + y_diff;
			cout << x3 << " " << y1 << " " << x4 << " " << y2;
		}
		else if (y_diff == 0)
		{
			int y3 = y1 + x_diff;
			int y4 = y2 + x_diff;
			cout << x1 << " " << y3 << " " << x2 << " " << y4;
		}
		else
		{
			cout << x1 << " " << y2 << " " << x2 << " " << y1;
		}

	}
	return 0;
}
