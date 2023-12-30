#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int                          long long
#define varname(name)                #name
#define mod                          1000000007
#define wer(x)                       cout<<"\n"<<varname(x)<<" here : \n"<<x
#define test                         int t; cin>>t; while(t--)
#define asdf(a,n)                    for(int i=0;i<n;i++)  cin>>a[i]
#define out(a,n)                     cout<<"\n"<<varname(a)<<" here is : \n";for(int i=0;i<n;i++) cout<<a[i]<<" "; cout<<endl
#define pb                           push_back

int gcd_of_number(int a, int b)
{
	if (b % a == 0)
	{
		return a;
	}
	else return gcd_of_number(b % a, a);
}

void extended_euclid(int w, int d, int &x0, int &y0, int global_gcd)
{
	if (d == 0)
	{
		x0 = 1;
		y0 = 0;
		global_gcd = w;
		return;
	}
	extended_euclid(d, w % d, x0, y0, global_gcd);
	int c_x = y0;
	int c_y = x0 - (w / d) * y0;
	x0 = c_x;
	y0 = c_y;
}

int32_t main()
{
//ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif

	int n, p, w, d;
	cin >> n >> p >> w >> d;
	if ( p % gcd_of_number(w, d) != 0 || (p > n * w))
	{
		cout << -1 << endl;
	}
	else
	{
		int k = p / gcd_of_number(w, d);
		//cout << k << endl;
		int x0, y0, global_gcd;
		extended_euclid(w, d, x0, y0, global_gcd);
		//cout << w << "( " << x0 << " ) + " << d << "( " << y0 << " ) = " << gcd_of_number(w, d) << endl;
		int x1 = k * x0;
		int y1 = k * y0;
		int gcd = gcd_of_number(w, d);
		//find general x and y


		int f = n - (x1 + y1);
		int ff = ((d / gcd) - (w / gcd));
		int t = f / (ff);

		t += 2;
		cout << t << endl;
		int x = x1 + (d / gcd) * t;
		int y = y1  - (w / gcd) * t;

		if (x < 0)
		{
			cout << -1 << endl;
		}
		else if (x + y > n)
		{
			cout << -1 << endl;
		}
		else cout << x << " " << y << " " << n - (x + y);




	}
	return 0;
}
