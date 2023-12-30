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
	test
	{
		int n;
		cin >> n;
		int a[n];
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		int low, high;
		cin >> low >> high;
		vector<int> v1, v2, v3;
		for (int i = 0; i < n; i++)
		{
			if (a[i] < low)
				v1.push_back(a[i]);
			else if (a[i] > high)
				v3.push_back(a[i]);
			else v2.push_back(a[i]);
		}
		for (auto x : v1)
		{
			cout << x << " ";
		}

		sort(v2.begin(), v2.end());
		for (auto x1 : v2)
		{
			cout << x1 << " ";
		}

		for (auto x2 : v3)
		{
			cout << x2 << " ";
		}
		cout << endl;
	}
	return 0;
}
