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
	bool is_tree()
	{
		bool *visited = new bool[V];
		int *parent = new int[V];
		for (int i = 0; i < V; i++)
		{
			visited[i] = false;
			parent[i] = i;
		}
		int src = 0;
		queue<int> q;
		q.push(src);
		visited[src] = true;
		while (!q.empty())
		{
			int node = q.front();
			q.pop();

			for (int nbr : l[node])
			{
				if (visited[nbr] == true && parent[node] != nbr)
				{
					return false;
				}
				else if (!visited[nbr])
				{
					visited[nbr] = true;
					parent[nbr] = node;
					q.push(nbr);
				}
			}
		}
		return true;

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
	Graph g1(4);
	g1.add_edge(0, 1);
	// g1.add_edge(1, 2);
	g1.add_edge(2, 3);
	g1.add_edge(3, 0);

	if (g1.is_tree())
	{
		cout << "Yes its a tree ";
	}
	else cout << "Not a tree";
	return 0;
}
