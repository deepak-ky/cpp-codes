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
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	test
	{
		int w;
		cin >> w;
		bool ispresent = binary_search(a, a + n, w);
		if (!ispresent)
		{
			cout << -1 << " " << -1 << endl;
		}
		else
		{
			auto lb = lower_bound(a, a + n, w);
			cout << lb - a << " ";
			auto ub = upper_bound(a, a + n, w);
			cout << ub - a - 1 << " ";
			cout << endl;
		}
	}

	return 0;
}
