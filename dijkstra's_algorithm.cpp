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
	list<pair<int, int> > *l;
public:
	Graph(int V)
	{
		this->V = V;
		l = new list<pair<int, int> >[V];
	}
	void add_edge(int x, int y, int wt)
	{
		l[x].push_back(make_pair(y, wt));
		l[y].push_back(make_pair(x, wt));
	}
	void display_edges()
	{
		for (int i = 0; i < V; i++)
		{
			cout << i << " nbr's : ";
			for (auto every : l[i])
			{
				cout << "(" << every.first << "," << every.second << ") ";
			}
			cout << endl;
		}


	}
	void dijkstra(int src)
	{
		map<int, int> dist;
		for (int i = 0; i < V; i++)
		{
			dist[i] = INT_MAX;
		}
		set<pair<int, int> > s;
		dist[src] = 0;
		s.insert(make_pair(0, src));
		while (!s.empty())
		{
			auto p = *(s.begin());
			int node = p.second;
			int nodedist = p.first;
			s.erase(s.begin());
			for (auto nbr : l[node])
			{
				if (nodedist + nbr.second < dist[nbr.first])
				{
					int dest = nbr.first;
					auto f = s.find(make_pair(dist[dest], dest));
					if (f != s.end())
					{
						s.erase(f);
					}
					dist[dest] = nodedist + nbr.second;
					s.insert(make_pair(dist[dest], dest));
				}
			}
		}
		for (auto every_pair : dist)
		{
			cout << src + 1 << "->" << every_pair.first + 1 << " : ";

			cout << every_pair.second << " ";
			cout << endl;
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
	//test {
	int v, e;
	cin >> v >> e;
	Graph g(v);
	for (int i = 0; i < e; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		u--; v--;
		g.add_edge(u, v, w);
	}
	//g.display_edges();
	for (int src = 1; src <= v; src++)
	{
		cout << "For Node " << src;
		cout << endl;
		cout << "--------------------------";
		cout << endl;
		int w = src - 1;
		g.dijkstra(w);
		cout << endl;
		cout << "--------------------------";
		cout << endl;
	}
	//}
	return 0;
}
