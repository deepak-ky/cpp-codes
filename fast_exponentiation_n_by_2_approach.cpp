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

int fast_expo(int a, int b)
{
	if (b == 0)
	{
		return 1;
	}

	if (b & 1)
	{
		return a * fast_expo(a, b / 2) * fast_expo(a, b / 2);
	}
	else return fast_expo(a, b / 2) * fast_expo(a, b / 2);
}

int32_t main()
{
//ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	int a, b;
	cin >> a >> b;
	cout << a << " ^ " << b << " :  " << fast_expo(a, b);
	return 0;
}