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
		int a, b, c, d;
		int x, y, x1, y1, x2, y2;
		cin >> a >> b >> c >> d >> x >> y >> x1 >> y1 >> x2 >> y2;
		bool flag1 = true;
		bool flag2 = true;
		int w = -a + b;
		int w1 = -c + d;
		if (((x + w) >= x1 && (x + w) <= x2) && ((x1 < x2) || (a + b == 0)))
		{
			flag1 = true;
		}
		else flag1 = false;
		if (((y + w1) >= y1 && (y + w1) <= y2) && ((y1 < y2) || (c + d == 0)))
		{
			flag2 = true;
		}
		else flag2 = false;

		if (flag1 && flag2)
		{
			cout << "Yes" << endl;
		}
		else cout << "No" << endl;
	}


	return 0;
}
