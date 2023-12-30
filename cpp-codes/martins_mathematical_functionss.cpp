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
const int N = 1000005;
int F[N] = {0};
int G[N] = {0};
void build_F()
{
	for (int i = 1; i < N; i++)
	{
		F[i] = F[i / 10] + (i & 1) * (i % 10);
	}
}
void build_G()
{
	for (int i = 1; i < N; i++)
	{
		for (int j = i; j < N; j += i)
		{
			G[j] += F[i];
		}
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
	build_F();
	build_G();
	test
	{
		int n;
		cin >> n;
		cout << G[n] << endl;
	}
	return 0;
}
