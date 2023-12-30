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
	int n, k;
	cin >> n >> k;
	vector<int> v;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		v.push_back(x);
	}
	while (k--)
	{
		int min_difference = INT_MAX;
		int index = -1;
		for (int i = 1; i < v.size() - 1; i++)
		{
			//wer(v[i]);
			int w = v[i + 1] - v[i - 1];
			//wer(w);
			if (w < min_difference)
			{
				min_difference = w;
				index = i;
			}
		}

		//wer(min_difference);
		//wer(index);
		v.erase(v.begin() + index);
	}
	cout << endl;
	for (auto x : v)
	{
		cout << x << " ";
	}

	return 0;
}
