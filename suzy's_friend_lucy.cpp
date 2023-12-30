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
	int max_rollno[n];
	max_rollno[0] = a[0];
	for (int i = 1; i < n; i++)
	{
		max_rollno[i] = (max_rollno[i - 1]) + a[i];
	}
	//out(max_rollno, n);
	test
	{
		int x;
		cin >> x;
		auto it = lower_bound(max_rollno, max_rollno + n, x);
		cout << it - max_rollno + 1 << endl;
	}

	return 0;
}
