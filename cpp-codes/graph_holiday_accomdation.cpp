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
class Graph
{
	int V;
	list< pair <int, int> > *l;
public:
	Graph(int v)
	{
		V = v;
		l = new list< pair <int, int> >[V];
	}
	void add_edge(int u, int v, int cost)
	{
		l[u].push_back(make_pair(v, cost));
		l[v].push_back(make_pair(u, cost));
	}
	int dfs_helper(int curr_node, bool * visited, int *count, int &ans)
	{
		visited[curr_node] = true;
		count[curr_node] = 1;
		for (auto every_nbr : l[curr_node])
		{
			int nbr = every_nbr.first;
			int wt = every_nbr.second;
			if (!visited[nbr])
			{
				count[curr_node] += dfs_helper(nbr, visited, count, ans);
				int nx = count[nbr];
				int ny = V - nx;
				ans += 2 * min(nx, ny) * wt;
			}
		}
		return count[curr_node];
	}
	int dfs()
	{
		bool *visted = new bool[V];
		int *count = new int[V];
		for (int i = 0; i < V; i++)
		{
			visted[i] = false;
			count[i] = 0;
		}
		int ans = 0;
		dfs_helper(0, visted, count, ans);
		return ans;
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
	int c = 1;
	test
	{
		int n;
		cin >> n;
		Graph g(n);
		for (int i = 1; i <= (n - 1); i++)
		{
			int u, v, w;
			cin >> u >> v >> w;
			u--; v--;
			g.add_edge(u, v, w);
		}
		cout << "Case #" << c << ": " << g.dfs() << endl;
		c++;

	}
	return 0;
}

