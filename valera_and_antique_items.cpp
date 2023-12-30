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
	int n, v1;
	cin >> n >> v1;
	vector<int> v;
	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		int n1;
		cin >> n1;
		int a[n1];

		for (int i = 0; i < n1; i++)
		{
			cin >> a[i];
		}
		sort(a, a + n1);
		if (v1 > a[0])
		{
			cnt++;
			v.push_back(i);
		}
	}
	cout << cnt << endl;
	for (auto x : v)
	{
		cout << x << " ";
	}

	return 0;
}
