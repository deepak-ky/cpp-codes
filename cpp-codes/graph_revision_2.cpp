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
	unordered_map<int, list<pair<int, int>> > mp;
public:
	void add_edge(int a, int b, int weight)
	{
		mp[a].push_back({b, weight});
		mp[b].push_back({a, weight});
	}
	void print_graph()
	{
		for (auto node : mp)
		{
			cout << node.first << "->";
			for (auto x : node.second)
			{
				cout << "(" << x.first << "," << x.second << "),";
			}
			cout << endl;
		}
	}
	void dijkstra(int src)
	{
		unordered_map<int, int> distance_from_parent;
		set< pair<int, int> > s;
		for (auto node : mp)
		{
			int vertex = node.first;
			distance_from_parent[vertex] = INT_MAX;
		}
		distance_from_parent[src] = 0;
		s.insert({0, src});
		while (!s.empty())
		{
			auto p = s.begin();
			int node = p->second;
			int node_distance = p->first;
			s.erase(p);
			for (auto nbr : mp[node])
			{
				if (distance_from_parent[nbr.first] > node_distance  + nbr.second)
				{
					if (s.find({distance_from_parent[nbr.first], nbr.first}) != s.end())
					{
						s.erase({distance_from_parent[nbr.first], nbr.first});
					}
					distance_from_parent[nbr.first] = node_distance  + nbr.second;
					s.insert({distance_from_parent[nbr.first], nbr.first});
				}
			}
		}
		for (auto x : distance_from_parent)
		{
			cout << src << " -> " << x.first << " : " << x.second << endl;
		}

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
	Graph g;
	g.add_edge(1, 2, 1);
	g.add_edge(1, 3, 4);
	g.add_edge(1, 4, 7);
	g.add_edge(2, 3, 1);
	g.add_edge(3, 4, 2);
	g.print_graph();
	cout << endl;
	g.dijkstra(1);
	return 0;
}
