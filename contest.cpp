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
	float a, b, c, d;
	cin >> a >> b >> c >> d;
	float val1_1 = (3 * a) / 10;
	float val2_1 = (3 * b) / 10;
	float val1_2 = a - ((a / 250) * c);
	float val2_2 = b - ((b / 250) * d);
	float val1 = max(val1_1, val1_2);
	float val2 = max(val2_1, val2_2);
	if (val1 > val2)
	{
		cout << "Misha";
	}
	else if (val2 > val1)
	{
		cout << "Vasya";
	}
	else cout << "Tie";

	return 0;
}
