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
	unordered_map<T , list < pair < T, int > > > g;
public:
	void add_edge(T x, T y, bool bidir, int wt)
	{
		g[x].push_back(make_pair(y, wt));
		if (bidir)
		{
			g[y].push_back(make_pair(x, wt));
		}
	}
	void print()
	{
		for (auto p : g)
		{
			cout << p.first << " -> ";
			list< pair<T, int> > w = p.second;
			for (auto q : w)
			{
				cout << "(" << q.first << "," << q.second << ")" << " , ";
			}
			cout << endl;
		}
	}
	void dijkstra_sssp(T src)
	{
		unordered_map<T, int> dist;
		for (auto j : g)
		{
			dist[j.first] = INT_MAX;
		}
		set<pair<int, T> > s;
		dist[src] = 0;
		s.insert(make_pair(0, src));
		while (!s.empty())
		{
			auto p = *(s.begin());
			T curr_node = p.second;
			int curr_node_dist = p.first;
			s.erase(s.begin());
			for (auto nbr : g[curr_node])
			{
				if (curr_node_dist + nbr.second < dist[nbr.first])
				{
					T dest = nbr.first;
					auto f = s.find(make_pair(dist[dest], dest));
					if (f != s.end())
					{
						s.erase(f);
					}

					dist[dest] = curr_node_dist + nbr.second;
					s.insert(make_pair(dist[dest], dest));
				}
			}

		}
		for (auto every_node : dist)
		{
			cout << every_node.first << " is at a distance of : " << every_node.second << endl;
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
	g1.add_edge(1, 2, true, 1);
	g1.add_edge(1, 3, true, 4);
	g1.add_edge(1, 4, true, 7);
	g1.add_edge(2, 3, true, 1);
	g1.add_edge(3, 4, true, 2);

	g1.dijkstra_sssp(1);



	return 0;
}
