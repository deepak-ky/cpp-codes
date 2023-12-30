#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int                          long long
#define varname(name)                #name
#define mod                          1000000007
#define wer(x)                    cout<<"\n"<<varname(x)<<" here : "<<x
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
	int w = 1;
	int sum = 0;
	while (n > 0)
	{
		int r = n % 10;
		r = r * w;
		sum = sum + r;
		w = w * 2;
		n = n / 10;
	}
	cout << sum;
	return 0;
}
