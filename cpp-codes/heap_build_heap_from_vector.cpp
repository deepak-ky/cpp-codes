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
void build_max_heap(vector<int> &v)
{
	for (int i = 2; i < v.size(); i++)
	{
		int idx = i;
		int parent = i / 2;
		while (idx > 1 && v[idx] > v[parent])
		{
			swap(v[idx], v[parent]);
			idx = parent;
			parent = parent / 2;
		}
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
	vector<int> v = { -1, 10, 20, 5, 6, 1, 8, 9, 4};
	for (auto x : v)
	{
		cout << x << " " ;
	}
	build_max_heap(v);
	cout << endl;
	for (auto x : v)
	{
		cout << x << " " ;
	}
	return 0;
}
