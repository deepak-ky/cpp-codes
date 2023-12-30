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
void run_operation(int *a, int s, int e, int v)
{
	for (int i = s; i <= e; i++)
	{
		a[i] = a[i] + v;
	}
}
class operation
{
public:
	int s;
	int e;
	int v;
};
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
	operation op[k];
	int m;
	cin >> m;
	int a[n];
	asdf(a, n);
	for (int i = 0; i < k; i++)
	{
		int w;
		cin >> w;
		w--;
		op[i].s = w;
		int d;
		cin >> d;
		d--;
		op[i].e = d;
		cin >> op[i].v;
	}
	while (m--)
	{
		int x, y;
		cin >> x >> y;
		x--; y--;
		for (int i = x; i <= y; i++)
		{
			run_operation(a, op[i].s, op[i].e, op[i].v);
		}

	}
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	return 0;
}
