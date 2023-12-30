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
	int V;
	list<pair<int, int > > *l;
	Graph(int V)
	{
		this->V = V;
		l = new list<pair<int, int > >[V];
	}
	void add_edge(int u, int v, int w)
	{
		l[u].push_back(make_pair(v, w));
		l[v].push_back(make_pair(u, w));
	}
	int findminvertex(int *weight, bool *visited, int V)
	{
		int minvertex = -1;
		for (int i = 0; i < V; i++)
		{
			if ( (!visited[i]) && ((minvertex == -1) || (weight[i] < weight[minvertex])))
			{
				minvertex = i;
			}
		}
		return minvertex;
	}
	void prim()
	{
		bool *visited = new bool[V];
		int *parent = new int[V];
		int *weight = new int[V];
		for (int i = 0 ; i < V; i++)
		{
			visited[i] = false;
			weight[i] = INT_MAX;
		}
		parent[0] = -1;
		weight[0] = 0;
		for (int i = 0; i < V; i++)
		{	//the find minvertex will give us that node which has not been visited and is of minimum weight;
			int minVertex = findminvertex(weight, visited, V);
			visited[minVertex] = true;
			for (auto nbr : l[minVertex])
			{
				if (!visited[nbr.first])
				{
					if (weight[nbr.first] > nbr.second)
					{
						//parent[nbr.first] = minVertex;
						weight[nbr.first] = nbr.second;
					}
				}
			}
		}
		for (int i = 1; i < V; i++)
		{
			cout << i << "--" << parent[i] << " with weight " << weight[i] << endl;
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
	int n, e;
	cin >> n >> e;
	Graph g(n);
	for (int i = 0; i < e; i++)
	{
		int u, v, w;
		cin  >> w >> u >> v;
		g.add_edge(u, v, w);

	}
	g.prim();
	return 0;
}
