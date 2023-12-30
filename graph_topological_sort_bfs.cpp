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
	}
	void topological_bfs()
	{
		int *indegree = new int[V];
		for (int i = 0; i < V; i++)
		{
			indegree[i] = 0;
		}

		for (int i = 0; i < V; i++)
		{
			for (auto every : l[i])
			{
				indegree[every]++;
			}
		}
		out(indegree, V);
		cout << endl;
		queue<int> q;
		for (int i = 0; i < V; i++)
		{
			if (indegree[i] == 0)
			{
				q.push(i);
			}
		}
		while (!q.empty())
		{
			int node = q.front();
			q.pop();
			cout << node << " ";
			for (auto nbr : l[node])
			{
				indegree[nbr]--;
				if (indegree[nbr] == 0)
				{
					q.push(nbr);
				}
			}
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
	Graph g1(6);
	g1.add_edge(0, 2);
	g1.add_edge(1, 2);
	g1.add_edge(1, 4);
	g1.add_edge(2, 3);
	g1.add_edge(2, 5);
	g1.add_edge(3, 5);
	g1.add_edge(4, 5);

	g1.topological_bfs();
	return 0;
}
