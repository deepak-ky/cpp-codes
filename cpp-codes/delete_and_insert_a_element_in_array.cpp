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


	string w;
	getline(cin, w);
	cout << w;
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i <  n; ++i)
	{
		/* code */cin >> a[i];
	}
	//delete(a, 4);
	return 0;
}
