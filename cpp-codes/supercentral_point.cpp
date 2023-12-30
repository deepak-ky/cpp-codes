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
	int x[n];
	int y[n];
	for (int i = 0; i < n; i++)
	{
		cin >> x[i] >> y[i];
	}
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		bool f1 = false;
		bool f2 = false;
		bool f3 = false;
		bool f4 = false;
		for (int j = 0; j < n; j++)
		{
			if ((x[i] > x[j]) && (y[i] == y[j])) f1 = true;
			if ((x[i] < x[j]) && (y[i] == y[j])) f2 = true;
			if ((x[i] == x[j]) && (y[i] > y[j])) f3 = true;
			if ((x[i] == x[j]) && (y[i] < y[j])) f4 = true;
		}
		if (f1 && f2 && f3 && f4) cnt++;
	}
	cout << cnt << endl;

	return 0;
}
