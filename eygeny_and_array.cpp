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
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif

	int n, m, a, l, r, c, d;
	c = d = 0;
	cin >> n >> m;
	while (n--)
	{
		cin >> a;
		if (a == 1)
		{
			c += 1;
		}
		else
		{
			d += 1;
		}
	}
	int up = min(c, d) * 2;
	while (m--)
	{
		cin >> l >> r;
		if (((r - l) % 2 == 1) && ((r - l) < up))
		{
			cout << 1 << endl;
		}
		else cout << 0 << endl;


	}
	return 0;
}
