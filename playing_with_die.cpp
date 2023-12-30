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
	int a, b;
	cin >> a >> b;
	int cnt1 = 0;
	int cnt2 = 0;
	int cnt3 = 0;
	for (int i = 1; i <= 6; i++)
	{
		int w1 = abs(i - a);
		int w2 = abs(i - b);
		if (w1 < w2)
		{
			cnt1++;
		}
		else if (w1 > w2)
		{
			cnt3++;
		}
		else cnt2++;
	}
	cout << cnt1 << " " << cnt2 << " " << cnt3;

	return 0;
}
