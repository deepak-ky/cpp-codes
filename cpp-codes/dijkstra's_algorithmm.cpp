#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int                          long long
#define varname(name)                #name
#define mod                          1000000007
#define wer(x)                       cout<<"\n"<<varname(x)<<" here : "<<x<<"\n"
#define asdf(a,n)                    for(int i=0;i<n;i++)  cin>>a[i]
#define out(a,n)                     cout<<"\n"<<varname(a)<<" here is : \n";for(int i=0;i<n;i++) cout<<a[i]<<" "; cout<<endl
#define pb                           push_back
#define yes                          cout << "YES" << endl;
#define no                           cout << "NO"  << endl;
#define f                            first
#define se                            second

void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
}

class graph
{
	int v;
	unordered_map< int, list< pair<int, int>  > > mp;
public:
	graph(int v)
	{
		this->v = v;
	}
	void add_edge(int a, int b, int wt)
	{
		mp[a].pb({b, wt});
		mp[b].pb({a, wt});
	}

	void dijkstra_sssp()
	{
		int src = 0;

		map<int, int> distance;
		for (int i = 0; i < v; i++)
		{
			distance[i] = INT_MAX;
		}
		distance[src] = 0;

		set< pair<int, int> > s;
		//I need the set to be sorted on the basis of distance ,
		//so the distance will become first
		s.insert({distance[src], src});
		while (!s.empty())
		{
			auto it = s.begin();
			int node = (*it).second;
			int curr_dist = (*it).first;
			s.erase(it);

			for (auto p : mp[node])
			{
				int nbr = p.first;
				int nbr_dist = p.second;
				if (curr_dist + nbr_dist < distance[nbr])
				{
					//there will two cases , whether first time or previously added
					auto it1 = s.find({distance[nbr], nbr});
					if (it1 != s.end())
					{
						s.erase(it1);
					}
					distance[nbr] = curr_dist + nbr_dist;
					s.insert({distance[nbr], nbr});
				}

			}

		}

		for (auto x : distance)
		{
			cout << src << "to" << x.first << " : " << x.second << endl;
		}
	}
};

int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{
		int n = 6;



		graph g(n);


		g.add_edge(0, 1, 10);
		g.add_edge(1, 2, 10);
		g.add_edge(2, 5, 10);
		g.add_edge(0, 3, 1);
		g.add_edge(3, 4, 10);
		g.add_edge(4, 5, 15);
		//Display the shortest path from src {0} to every other vertex
		g.dijkstra_sssp();
	}
	return 0;
}
