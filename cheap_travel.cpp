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
	int n, m, a, b;
	cin >> n >> m >> a >> b;
	int op1 = n * a;
	int op2 = INT_MAX;
	if (n % m == 0)
	{
		op2  = (n / m) * b;
	}
	int r = n % m;
	int q = n / m;
	int i = min((r * a), b);
	int op3  = (q * b) + i;
	int w = min(op1, op2);
	cout << min(w, op3);
	return 0;
}