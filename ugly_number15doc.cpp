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
	int notugly[10005];
	notugly[0] = 1;
	int i = 1;
	int j = 2;
	while (i < 10005)
	{
		if ((j % 2 == 0) || (j % 3 == 0) || (j % 5 == 0))
		{
			notugly[i] = j;
			j++;
			i++;
		}
		else {
			j++;
		}
	}
	cout << notugly[15 - 1];
	return 0;
}
