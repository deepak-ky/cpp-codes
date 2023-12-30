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
	asdf(a, n);
	int li[n];
	for (int i = 0; i < n; i++)
	{
		li[i] = 1;
	}
	for (int i = 1; i < n; i++)
	{
		if (a[i] > a[i - 1])
		{
			if (li[i] <= li[i - 1])
				li[i] = li[i - 1] + 1;
		}

	}
	for (int i = (n - 2); i >= 0 ; i--)
	{
		if (a[i] > a[i + 1])
		{
			if (li[i] <= li[i + 1])
				li[i] = li[i + 1] + 1;
		}

	}
	out(li, n);
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum = sum + li[i];
	}
	cout << endl << sum;
	return 0;
}
