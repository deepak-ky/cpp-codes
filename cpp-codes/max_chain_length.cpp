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
struct fs
{
	int first;
	int second;
};
int fpl(fs v[], int idx, int n, int val)
{
	if (idx >= n)
	{
		return 0;
	}
	fs p = v[idx];
	if (p.first > val)
	{
		return max((1 + fpl(v, idx + 1, n, p.second)), fpl(v, idx + 1, n, val));
	}
	else
	{
		return  fpl(v, idx + 1, n, val);
	}
}
int32_t main()
{
//ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
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
		fs * v = new fs[n];
		for (int i = 0; i < n; i++)
		{
			cin >> v[i].first >> v[i].second;
		}
		cout << fpl(v, 0, n, INT_MIN) << endl;
	}
	return 0;
}
