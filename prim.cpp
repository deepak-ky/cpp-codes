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
public:
	int v;
	list<pair<int, int> > *l;
	Graph(int n)
	{
		v = n;
		l = new list<pair<int , int > >[n];
	}
	void add_edge(int u, int v, int w)
	{
		l[u].push_back({v, w});
		l[v].push_back({u, w});
	}
	int find_min_vertex(bool * visited, int * weight)
	{
		int min_vertex = -1;
		for (int i = 0; i < v; i++)
		{
			if (  (!visited[i]) &&  /*{ */ ((min_vertex == -1) || (weight[i] < weight[min_vertex])) /*}*/ )
			{
				min_vertex = i;
			}
		}
		return min_vertex;
	}
	void prim()
	{
		bool * visited = new bool[v];
		int * weight = new int[v];
		int * parent = new int[v];
		for (int i = 0; i < v; i++)
		{
			visited[i] = false;
			weight[i] = INT_MAX;
		}
		weight[0] = 0;
		parent[0] = 0;
		for (int i = 0; i < v; i++)
		{
			int min_vertex = find_min_vertex(visited, weight);
			visited[min_vertex] = true;
			for (auto nbr : l[min_vertex])
			{
				if (!visited[nbr.first])
				{
					if (weight[nbr.first] > nbr.second)
					{
						weight[nbr.first] = nbr.second;
						parent[nbr.first] = min_vertex;
					}
				}
			}
		}
		int min_spanning_tree_weight = 0;
		for (int i = 0; i < v; i++)
		{
			cout << i << "--" << parent[i] << " with weight of : " << weight[i] << endl;
			min_spanning_tree_weight += weight[i];
		}
		cout << "\nThe min_spanning_tree_weight is : " << min_spanning_tree_weight << endl;
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
	int vertices;
	int edges;
	cin >> vertices >> edges;
	Graph g(vertices);
	for (int i = 0; i < edges; i++)
	{
		int w, u, v;
		cin >> w >> u >> v;
		g.add_edge(u, v, w);
	}
	g.prim();
	return 0;
}
