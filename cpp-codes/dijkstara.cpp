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
	map<char, list<pair<char, int> > > mp;
	void add_edge(char a, char b, int w)
	{
		mp[a].push_back({b, w});
		mp[b].push_back({a, w});
	}
	void print()
	{
		for (auto x : mp)
		{
			cout << x.first << " -> ";
			for (auto y : x.second)
			{
				cout << "( " << y.first << "," << y.second << " ),";
			}
			cout << endl;
		}
	}
	void dijkstra(char src , char dest)
	{
		unordered_map< char , int > dist_from_src;
		unordered_map< char , char > parent;
		for (auto x : mp)
		{
			dist_from_src[x.first] = INT_MAX;
		}
		for (auto x : mp)
		{
			parent[x.first] = x.first;
		}
		dist_from_src[src] = 0;
		set< pair < int, char> > s;
		s.insert( {0, src} );
		while (!s.empty())
		{
			auto f = s.begin();
			s.erase(f);
			char node = f->second;
			int curr_node_dist = f->first;

			for (auto nbr : mp[node])
			{
				if ((curr_node_dist + nbr.second) < dist_from_src[nbr.first])
				{
					auto f = s.find( {dist_from_src[nbr.first] , nbr.first} );
					if ( f != s.end() )
					{
						s.erase(f);
					}
					dist_from_src[nbr.first] = curr_node_dist + nbr.second;
					s.insert( { (curr_node_dist + nbr.second)  , nbr.first});
					parent[nbr.first] = node;
				}
			}
		}
		cout << "The distance's are : ";
		for (auto x : dist_from_src)
		{
			cout << src << "->" << x.first << " : " << x.second;
			cout << endl;
		}
		cout << "The path is : ";
		cout << dest << "<-";
		while ( parent[dest] != src )
		{
			cout << parent[dest] << "<-";
			dest = parent[dest];
		}
		cout << src;
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
	g.add_edge('S', 'B' , 4);
	g.add_edge('S', 'C' , 3);
	g.add_edge('B', 'F' , 5);
	g.add_edge('B', 'E' , 12);
	g.add_edge('C', 'E' , 10);
	g.add_edge('C', 'D' , 7);
	g.add_edge('E', 'G' , 5);
	g.add_edge('E', 'D' , 2);
	g.add_edge('F', 'G' , 16);
	//g.print();
	g.dijkstra('S', 'G');

	return 0;
}
