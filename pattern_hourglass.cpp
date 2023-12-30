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

	int left = n;

	int value = 0;
	while (left != 0)
	{
		for (int i = 1; i <= (value); i++)
		{
			cout << "  ";
		}
		for (int i = left; i >= 0; i--)
		{
			cout << i << " ";
		}
		for (int i = 1; i <= left; i++)
		{
			cout << i << " ";
		}

		cout << endl;
		value++;
		left--;

	}
	for (int i = 0; i < n; i++)
	{
		cout << "  ";
	}
	cout << "0" << endl;
	int value1 = n;
	int right = 1;
	while (right <= 5)
	{
		for (int i = 0; i < value1; i++)
		{
			cout << "  ";
		}
		for (int i = right; i >= 0; i++)
		{
			cout << i << " ";
		}
		for (int i = 1; i <= right; i++)
		{
			cout << i << " ";
		}
		cout << endl;
		right++;
		value1--;
	}
	return 0;
}
