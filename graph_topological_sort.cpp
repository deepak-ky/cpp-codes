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
template<typename T>
class Graph
{
	unordered_map<T , list < T > > g;
public:
	void add_edge(T x, T y)
	{
		g[x].push_back(y);
		//g[y].push_back(x);
	}
	void dfs_helper(T src, unordered_map<int, bool> &visited, list<T> &ordering)
	{
		//cout << src << " ";
		visited[src] = true;
		for (auto nbr : g[src])
		{
			if (!visited[nbr])
				dfs_helper(nbr, visited, ordering);
		}
		ordering.push_front(src);
		return;
	}
	void dfs_topological()
	{
		unordered_map<int, bool> visited;
		list<T> ordering;
		for (auto every_node : g)
		{
			T a = every_node.first;
			visited[a] = false;
		}
		int cnt = 0;
		for (auto  n : g)
		{
			T node = n.first;

			if (!visited[node])
			{

				dfs_helper(node, visited, ordering);

				cnt++;
			}

		}
		cout << "\nThe topological sort : \n";
		for (auto every_int : ordering)
		{
			cout << every_int << " ";
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
	Graph<int> g1;

	g1.add_edge(1, 3);
	g1.add_edge(3, 4);
	g1.add_edge(1, 2);
	g1.add_edge(2, 4);
	g1.dfs_topological();
	return 0;
}
