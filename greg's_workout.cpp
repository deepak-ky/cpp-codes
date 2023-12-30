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
	int cnt1 = 0;
	int cnt2 = 0;
	int cnt3 = 0;
	int flag1 = 1;
	int flag2 = 0;
	int flag3 = 0;
	for (int i = 0; i < n; i++)
	{
		if (flag1)
		{
			cnt1 += a[i];
			flag1 = 0;
			flag2 = 1;
			flag3 = 0;
		}
		else if (flag2)
		{
			cnt2 += a[i];
			flag1 = 0;
			flag2 = 0;
			flag3 = 1;
		}
		else if (flag3)
		{
			cnt3 += a[i];
			flag1 = 1;
			flag2 = 0;
			flag3 = 0;
		}
	}
	if (cnt1 >= cnt2 && cnt1 >= cnt3)
	{
		cout << "chest";
	}
	else if (cnt2 >= cnt1 && cnt2 >= cnt3)
	{
		cout << "biceps";
	}
	else cout << "back";

	return 0;
}
