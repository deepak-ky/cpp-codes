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
		string ans = "";
		int p = 1;
		int a, b;
		cin >> a >> b;
		while (a > 0)
		{
			int r1 = a % 10;
			int r2 = b % 10;
			int bit = 1;
			if (r1 == r2)
			{
				bit = 0;
			}
			string b1 = to_string(bit);
			ans = b1 + ans;
			a = a / 10;
			b = b / 10;
		}
		cout << ans << endl;
	}
	return 0;
}
