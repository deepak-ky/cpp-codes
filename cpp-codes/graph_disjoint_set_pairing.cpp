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
struct dsu
{
	vector<int> par, sz;
	int total_comp;

	void init(int n)
	{
		par.resize(n);
		sz.resize(n);
		for (int i = 0; i < n; i++) par[i] = i;
		for (int i = 0; i < n; i++) sz[i] = 1;
		int total_comp = n;
	}
	int get_superparent(int x)
	{
		if (x == par[x])
		{
			return x;
		}
		else return (par[x] = get_superparent(par[x]));
	}
	void unite(int x, int y)
	{
		int super_parent_x = get_superparent(x);
		int super_parent_y = get_superparent(y);
		if (super_parent_x != super_parent_y)
		{
			par[super_parent_x] = super_parent_y;
			sz[super_parent_y] += sz[super_parent_x];
			sz[super_parent_x] = 0;
			total_comp--;
		}

	}

};
int32_t main()
{

#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	int n, m;
	cin >> n >> m;
	dsu G;
	G.init(n);
	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		G.unite(x, y);
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		int super_parent_i = G.get_superparent(i);
		ans += n - G.sz[super_parent_i];
	}
	cout << ans / 2;
	return 0;
}
