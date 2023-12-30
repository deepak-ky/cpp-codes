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
	int n, m;
	cin >> n >> m;
	if (m == 1)
	{
		int ans = n * (n - 1);
		cout << ans / 2 << " " << ans / 2;
	}
	else
	{

		if (n % m == 0)
		{
			//har ek team mein kitne bande aayenge
			int w1 = n / m;
			//toh agar 9 bando ko 3 team mein divide karna hain toh har ek team mein 3 bande aayenge aur phir unka combinations lena hain
			int ans1 = ((w1 * (w1 - 1)) / 2);
			ans1 = ans1 * m;
			cout << ans1;
		}
		else
		{
			int sum = 0;
			int q = n / m;
			int r = n % m;
			int w2 = m - r;
			int ans1 = ((q * (q - 1)) / 2);
			sum += (ans1 * w2);
			int w3 = q + 1;
			int ans2 = ((w3 * (w3 - 1)) / 2);
			sum += ans2 * r;
			cout << sum;

		}
		int w = n - m + 1;

		int ans = w * (w - 1);

		cout << " " << ans / 2;

	}
	return 0;
}
