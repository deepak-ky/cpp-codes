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
struct DSU
{
	vector<int> par, sz;
	int total_comp;
	void init(int n)
	{
		par.resize(n);
		sz.resize(n);
		for (int i = 0; i < n; i++) par[i] = i;
		for (int i = 0; i < n; i++) sz[i] = 1;
		total_comp = n;
	}
	int super_parent(int x)
	{
		if (x == par[x])
		{
			return x;
		}
		else return par[x] = super_parent(par[x]);
	}
	void unite(int a, int b)
	{
		int sp_a = super_parent(a);
		int sp_b = super_parent(b);

		par[sp_a] = sp_b;
		sz[b] += sz[a];
		sz[a] = 0;
		total_comp--;

	}
};
int32_t main()
{
//ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	int n = 4;
	DSU dsu;
	dsu.init(4);
	bool flag = false;
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		wer(x);
		wer(y);
		wer(dsu.super_parent(x));
		wer(dsu.super_parent(y));
		if (dsu.super_parent(x) != dsu.super_parent(y))
		{
			dsu.unite(x, y);
		}
		else
		{
			flag = true;
			cout << "This edge will lead to cycle in  the graph!!";
			break;
		}
		wer(dsu.super_parent(x));
		wer(dsu.super_parent(y));

	}
	if (flag)
	{
		cout << "The graph contains a cycle!";

	}
	else cout << "The graph does not contain a cycle!!";
	return 0;
}
