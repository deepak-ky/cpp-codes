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
	vector<int> v1;
	vector<int> v2;
	vector<int> v3;
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] < 0)
		{
			cnt++;
		}
		else if (a[i] == 0)
		{
			v3.push_back(a[i]);
		}
	}
	if (cnt == 1)
	{
		for (int i = 0; i < n; i++)
		{
			if (a[i] < 0)
			{
				v1.push_back(a[i]);
			}
		}
	}
	else if (cnt == 2)
	{
		for (int i = 0; i < n; i++)
		{
			if (a[i] < 0)
			{
				if (v1.size() != 1)
				{
					v1.push_back(a[i]);
				}
				else v3.push_back(a[i]);
			}
		}
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			if (a[i] < 0)
			{
				if (v1.size() != 1)
				{
					v1.push_back(a[i]);
				}
				else if (v2.size() != 2)
				{
					v2.push_back(a[i]);
				}
				else v3.push_back(a[i]);
			}
		}
	}
	for (int i = 0; i < n; i++)
	{

		if (a[i] > 0)
		{
			v2.push_back(a[i]);
		}

	}
	cout << v1.size() << " ";
	for (auto x : v1)
	{
		cout << x << " ";
	}
	cout << endl;
	cout << v2.size() << " ";
	for (auto x : v2)
	{
		cout << x << " ";
	}
	cout << endl;
	cout << v3.size() << " ";
	for (auto x : v3)
	{
		cout << x << " ";
	}

	return 0;
}
