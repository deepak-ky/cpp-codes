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

	void init(int n)
	{
		par.resize(n);
		for (int i = 0; i < n; i++) par[i] = i;
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
			//total_comp--;
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
	int flag = 0;
	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		if ( G.get_superparent(x) != G.get_superparent(y))
		{
			G.unite(x, y);
		}
		else
		{
			flag = 1;
			cout << x << " " << y << " this edge will lead to cycle in the graph";
		}

	}
	if (flag == 0 )
	{
		cout << "\nThe graph does not contain a cycle ";
	}
	else cout << "\nThis graph contains cycle ";
	return 0;
}
