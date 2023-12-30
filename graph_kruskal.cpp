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
class edge
{
public:
	int wt;
	int src;
	int dest;
};
bool compare(edge e1, edge e2)
{
	return e1.wt <= e2.wt;
}
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
	edge edges[m];
	for (int i = 0; i < m; i++)
	{
		int w, x, y;
		cin >> w >> x >> y; //taking weight input first here
		edges[i].wt = w;
		edges[i].src = x;
		edges[i].dest = y;
	}
	sort(edges, edges + m, compare);
	int ans = 0;
	for (int i = 0; i < m; i++)
	{
		int w = edges[i].wt;
		int x = edges[i].src;
		int y = edges[i].dest;

		if (G.get_superparent(x) != G.get_superparent(y))
		{
			G.unite(x, y);
			cout << w << " " << x << " " << y << endl;
			ans += w;
		}
	}
	cout << endl << ans;
	return 0;
}
