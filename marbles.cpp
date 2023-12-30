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
		int n, k;
		cin >> n >> k;
		if ( n == k) cout << 1 << endl;
		else
		{
			int prod1 = 1;
			int prod2 = 1;
			for (int i = (n - 1); i >= (n - k + 1); i--)
			{
				prod1 = prod1 * (i);
			}
			for (int i = 1; i < k; i++)
			{
				prod2 = prod2 * (i);
			}
			cout << prod1 / prod2 << endl;
		}
	}
	return 0;
}
