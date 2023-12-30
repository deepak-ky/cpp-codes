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
		int a; int b;
		cin >> a >> b;

		int w = abs(a - b);
		int ans = 0;
		int p = 0;
		for (int i = 0; i <= 31; i++)
		{
			int w1 = pow(2, p);
			p++;
			if (w < w1)
			{
				int bit;
				int w2 = a >> i;
				int bit1 = 0;
				if (w2 & 1) bit1 = 1;
				int w3 = b >> i;
				int bit2 = 0;
				if (w3 & 1) bit2 = 1;

				bit = bit1 & bit2;
				ans += (w1 * bit);
			}
		}
		cout << ans << endl;


	}

	return 0;
}
