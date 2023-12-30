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



	int dijkstra_ssssp(int max_time , int* passing_Fees)
	{
		map<int, int> distance;
		map<int, int> cost;
		for (int i = 0; i < v; i++)
		{
			distance[i] = INT_MAX;
			cost[i] = INT_MAX;
		}

		distance[0] = 0;
		cost[0] = passing_Fees[0];

		set < pair<int, pair<int, int>> > s;

		s.insert({cost[0], {distance[0] , 0}});

		while (!s.empty())
		{
			auto it = s.begin();
			int node = (*it).second.second;
			int dist_current = (*it).second.first;
			int cc = (*it).first;
			s.erase(it);

			for (auto p : mp[node])
			{
				int nbr = p.first;
				int nbr_distance = p.second;

				if (dist_current + nbr_distance > max_time) continue;
				else
				{
					if (cc + passing_Fees[nbr] < cost[nbr])
					{
						auto it = s.find({cost[nbr] , {distance[nbr], nbr}});
						if (it != s.end())
						{
							s.erase(it);
						}

						cost[nbr] = cc + passing_Fees[nbr];
						distance[nbr] = dist_current + nbr_distance;

						s.insert({cost[nbr] , {distance[nbr], nbr}});
					}
				}



				/*	wer(distance[nbr.first]);
					wer(cost[nbr.first]);*/

			}
		}

		/*for (auto x : distance)
		{
			cout << x.first << " " << x.second << endl;
		}


		for (auto x : cost)
		{
			cout << x.first << " " << x.second << endl;
		}*/
		if (cost[v - 1] == INT_MAX) return -1;
		else return cost[v - 1];
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
		int a[6] = {5, 1, 2, 20, 20, 3};
		cout << g.dijkstra_ssssp(25, a);

	}
	return 0;
}
