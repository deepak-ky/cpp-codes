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

bool isanyindexzero(int a[], int n, int k, int value)
{

	if (k < 0 || k >= n)
	{

		return false;
	}


	//Recursion case
	if (a[k] == 0)
	{
		return true;
	}
	else
	{
		if ((k + a[k]) == value || k - a[k] == value)
		{
			return false;
		}
		else return (isanyindexzero(a, n, k + a[k], value) || isanyindexzero(a, n, k - a[k], value));
	}
}
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
	int k;
	cin >> k;
	int a[n];
	asdf(a, n);
	if (isanyindexzero(a, n, k, k))
	{
		cout << "true";
	}
	else
	{
		cout << "false";
	}
	return 0;
}
