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
	list<int> *l;
public:
	Graph(int V)
	{
		this->V = V;
		l = new list<int>[V];
	}
	void add_edge(int u, int v)
	{
		l[u].push_back(v);
		l[v].push_back(u);
	}
	void dfs_helper(int src, unordered_map<int, bool> &visited)
	{
		visited[src] = true;
		for (auto nbr : l[src])
		{
			if (!visited[nbr])
			{
				dfs_helper(nbr, visited);
			}
		}
	}
	int dfs(int src, int a, int b)
	{
		unordered_map<int, bool> visited;
		for (int i = 0; i < V; i++)
		{
			visited[i] = false;
		}
		int c = 0;
		for (int i = 0; i < V; i++)
		{
			if (!visited[i])
			{
				dfs_helper(src, visited);
				c++;
			}
		}
		int size = l->size();
		size++;
		int total_cost = a * c + b * (size - c) + a * (V - size);
		return total_cost;

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
	test
	{
		int n, m , a , b;
		cin >> n >> m >> a >> b;
		int ans = n * a;
		Graph g(n);
		for (int i = 0; i < m; i++)
		{
			int u, v;
			cin >> u >> v;
			u--; v--;
			g.add_edge(u, v);
		}
		int t = g.dfs(0, a, b);

		cout << min(ans, t) << endl;
	}
	return 0;
}
