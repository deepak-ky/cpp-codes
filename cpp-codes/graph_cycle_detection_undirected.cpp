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
	void add_edge(int x, int y)
	{
		l[x].push_back(y);
		l[y].push_back(x);
	}
	bool has_cycle_helper(int node, bool *visited, int parent)
	{
		visited[node] = true;
		for (auto nbr : l[node])
		{
			if (!visited[nbr])
			{
				bool cycle_mila = has_cycle_helper(nbr, visited, node);
				if (cycle_mila)
				{
					return true;
				}
			}
			else if (nbr != parent)
			{
				return true;
			}
		}
		return false;
	}
	bool has_cycle()
	{
		bool *visited = new bool[V];
		for (int i = 0; i < V; i++)
		{
			visited[i] = false;
		}
		return has_cycle_helper(0, visited, -1);

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
	Graph g1(5);
	g1.add_edge(0, 1);
	g1.add_edge(1, 2);
	g1.add_edge(2, 3);
	g1.add_edge(3, 4);
	g1.add_edge(4, 0);
	if (g1.has_cycle())
	{
		cout << "It contains cycle ";
	}
	else cout << "It does not contain cyle";
	return 0;
}
