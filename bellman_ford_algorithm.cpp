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
	vector<vector<int>> edge_list;
public:
	graph(int v)
	{
		this->v = v;
	}
	void add_edge(int a, int b, int wt)
	{

		vector<int> r;
		r.pb(a);
		r.pb(b);
		r.pb(wt);

		edge_list.pb(r);
	}

	void negative_wt_cycle()
	{
		unordered_map<int, int> distance;
		for (int i = 0; i < v; i++)
		{
			distance[i] = INT_MAX;
		}
		distance[0] = 0;
		int number_of_edges = edge_list.size();

		//The loop should v-1 times
		for (int i = 0; i < (v - 1); i++)
		{
			for (int j = 0; j < number_of_edges; j++)
			{
				int src = edge_list[j][0];
				int dest = edge_list[j][1];
				int wt = edge_list[j][2];

				if (distance[src] == INT_MAX && distance[dest] == INT_MAX)
				{
					continue;
				}
				else
				{
					if (distance[dest] > distance[src] + wt)
					{
						distance[dest] = distance[src] + wt;
					}
				}

			}
		}

		bool is_present = false;
		for (int j = 0; j < number_of_edges; j++)
		{
			int src = edge_list[j][0];
			int dest = edge_list[j][1];
			int wt = edge_list[j][2];

			if (distance[src] != INT_MAX && distance[dest] != INT_MAX)
			{
				if (distance[dest] > distance[src] + wt)
				{
					is_present = true;
					break;
				}
			}

		}

		if (is_present)
		{
			cout << "The graph contains negative_wt_cycle";
		}
		else
		{
			for (auto x : distance)
			{
				cout << 0 << " -> " << x.first << " :  " << x.second << endl;
			}
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
		/*cin >> v >> e;*/
		int v = 3;
		graph g(v);
		//v-> is the number of vertices
		//e-> is the number of edges
		//edges would be stored in a vector of vector
		//for (int i = 0; i < e; i++)
		/*{
			//int a, b, wt;
			//cin >> a >> b >> wt;
			//g.add_edge(a, b, wt);
		}


		*/
		g.add_edge(0, 1, 3);
		g.add_edge(1, 2, 4);
		g.add_edge(0, 2, -10);
		g.negative_wt_cycle();

	}
	return 0;
}
