#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int                          long long
#define varname(name)                #name
#define mod                          1000000007
#define wer(x)                       cout<<"\n"<<varname(x)<<" here : "<<x
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
	int t; cin >> t; while (t--)
	{
		int n;
		cin >> n;
		int a[n];
		asdf(a, n);
		int l_b_zero = 0;
		int l_b_set = 0;
		for (int i = 0; i < n; i++)
		{

			if ((a[i] & 1) > 0)
			{
				l_b_set++;
			}
			else l_b_zero++;

		}
		cout << l_b_zero*l_b_set << endl;
	}

	return 0;
}
