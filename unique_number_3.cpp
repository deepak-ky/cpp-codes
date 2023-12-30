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
//ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	int *a = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	map<int, int> bits;
	for (int i = 0; i < 32; i++)
	{
		bits[i] = 0;
	}
	for (int i = 0; i < n; i++)
	{
		int val = a[i];
		for (int j = 0; j < 31; j++)
		{
			if ((val >> j) & 1)
			{
				bits[j]++;
			}
		}
	}
	int p = 1;
	int ans = 0;
	for (int i = 0; i < 32; i++)
	{
		if ((bits[i] % 3))
		{
			ans += p;
		}
		p = p * 2;
	}
	cout << ans;
	return 0;
}
