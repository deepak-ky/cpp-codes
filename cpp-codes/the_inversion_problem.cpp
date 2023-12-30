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
int calc_inversion(vector<int> v)
{
	int sum = 0;
	for (int i = 0; i < (v.size() - 1); i++)
	{
		for (int j = i + 1; j < v.size(); j++)
		{
			if (b[j] < a[i])
			{
				sum++;
			}
		}
	}
	return sum;
}
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
	vector<int> v;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		v.push_back(x);
	}
	for (int i = 0; i < n; i++)
	{
		int w = v[0];
		v.erase(v.begin());
		v.insert(v.end(), w);
		cout << calc_inversion(v) << " ";

	}

	return 0;
}
