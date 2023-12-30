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
	vector<int> v;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		v.push_back(x);
	}
	while ((v.size() != 1))
	{
		int t;
		int d;
		cin >> t;
		cin >> d;
		vector<int> v1(v);
		sort(v1.begin(), v1.end());
		int a = v1[0];
		int b = v1[1];
		auto it = find(v.begin(), v.end(), a);
		v.erase(it);
		auto it1 = find(v.begin(), v.end(), b);
		v.erase(it1);

		if ( t == 1)
		{
			v.push_back((a + b + d));;
		}
		else
		{
			v.push_back(((a - b) + d));
		}
	}
	cout << v[0];






	return 0;
}
