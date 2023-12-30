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
		g[y].push_back(x);
	}
	void dfs_helper(T src, unordered_map<int, bool> &visited)
	{
		cout << src << " ";
		visited[src] = true;
		for (auto nbr : g[src])
		{
			if (!visited[nbr])
				dfs_helper(nbr, visited);
		}
	}
	void dfs_cc()
	{
		unordered_map<int, bool> visited;
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
				cout << "Component " << cnt << " --> ";
				dfs_helper(node, visited);
				cout << endl;
				cnt++;
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
	Graph<int> g1;
	g1.add_edge(0, 1);
	g1.add_edge(0, 3);
	g1.add_edge(0, 4);
	g1.add_edge(1, 2);
	g1.add_edge(2, 3);

	g1.add_edge(5, 6);
	g1.add_edge(6, 7);

	g1.add_edge(8, 8);
	g1.dfs_cc();
	return 0;
}
