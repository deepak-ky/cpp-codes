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
	int src;
	int dest;
	int weight;
};
class Graph
{
public:
	int V, E;
	edge *edges;
	Graph(int V, int E)
	{
		this->V = V;
		this->E = E;
		edges = new edge[E];
	}
	void add_edge(int u, int v, int w, int count)
	{
		edges[count].src = u;
		edges[count].dest = v;
		edges[count].weight = w;
	}
	void Bellman_ford(int sr)
	{
		int distance[V];
		for (int i = 0; i < V; i++)
		{
			if (i == sr)
			{
				distance[i] = 0;
			}
			else distance[i] = INT_MAX;
		}

		//do relaxation v-1 time
		for (int i = 1; i <= (V - 1); i++)
		{
			for (int j = 0; j < E; j++)
			{
				int sorc = edges[j].src;
				int dest = edges[j].dest;
				int wt = edges[j].weight;
				//relaxation check
				if ( (distance[sorc] != (INT_MAX)) && (distance[sorc] + wt < distance[dest]))
				{
					distance[dest] = distance[sorc] + wt;
				}
			}
		}
		//for checking negative wieght cycle relaxation needs to be done one more time and if any value changes then the graph has a negative weight cycle
		for (int j = 0; j < E; j++)
		{
			int sorc = edges[j].src;
			int dest = edges[j].dest;
			int wt = edges[j].weight;
			//relaxation check
			if ( (distance[sorc] != (INT_MAX)) && (distance[sorc] + wt < distance[dest]))
			{
				cout << "\nThe graph contains a negative weight cycle";
				return;
			}
		}
		for (int i = 0; i < V; i++)
		{
			cout << sr << "-->" << i << " : " << distance[i] << endl;
		}
		return;
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
	int v, e;
	cin >> v >> e;
	Graph g(v, e);
	for (int i = 0; i < e; i++)
	{
		int u, v, d;
		cin >> u >> v >> d;
		g.add_edge(u, v, d, i);
	}
	g.Bellman_ford(0);
	return 0;
}
