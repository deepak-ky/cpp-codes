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
	int z[n];
	for (int i = 0; i < n; i++)
	{
		cin >> x[i] >> y[i] >> z[i];
	}
	int sum1 = 0;
	int sum2 = 0;
	int sum3 = 0;
	for (int i = 0; i < n; i++)
	{
		sum1 += x[i];
		sum2 += y[i];
		sum3 += z[i];
	}
	if (sum1 != 0 || sum2 != 0 || sum3 != 0)
	{
		cout << "NO";
	}
	else cout << "YES";
	return 0;
}
