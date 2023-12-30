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
	//int a[n];
	int first_even = -1;
	int first_odd = -1;
	map<string, int> mp;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		if (x & 1)
		{
			mp["odd"]++;
			if (first_odd == -1)
			{
				first_odd = i;
			}
		}
		else
		{
			mp["even"]++;
			if (first_even == -1)
			{
				first_even = i;
			}
		}


	}
	//wer(first_even);
	//wer(first_odd);
	if (mp["even"] == 1)
	{
		cout << first_even + 1;
	}
	else cout << first_odd + 1;

	return 0;
}
