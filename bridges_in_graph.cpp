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
	unordered_map< int , list<int>> mp;
	int current_time;
	int cnt = 0;

public:

	graph(int v)
	{
		this->v = v;
		current_time = 0;
	}

	void add_Edge(int a, int b)
	{
		mp[a].push_back(b);
		mp[b].push_back(a);
	}

	void dfs(int node, int *parent, int *disc, int *low)
	{
		//wer(node);

		disc[node]  = current_time;
		low[node] = current_time;
		current_time++;

		/*		out(disc, v);
				out(low, v );
				out(parent, v);
		*/
		for (auto nbr : mp[node])
		{
			//wer(nbr);
			if (disc[nbr] == -1)
			{
				parent[nbr] = node;
				dfs(nbr, parent, disc, low);
				low[node] = min(low[nbr], low[node]);

				if (low[nbr] > disc[node])
				{
					cout << node << " -> " << nbr << endl;
					cnt++;
				}
			}
			else if (parent[node] != nbr)
			{
				low[node] = min(low[node], disc[nbr]);
			}

			/*		out(disc, v);
					out(low, v );
					out(parent, v);*/
		}
	}

	void number_of_bridges()
	{
		int parent[v];
		int disc[v];
		int low[v];

		for (int i = 0; i < v; i++)
		{
			parent[i] = disc[i] = low[i] = -1;
		}

		for (int i = 0; i < v; i++)
		{
			if (disc[i] == -1)
			{
				dfs(i, parent, disc, low);
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
		graph g(6);
		g.add_Edge(0, 1);
		g.add_Edge(1, 2);
		g.add_Edge(2, 0);
		g.add_Edge(0, 3);
		g.add_Edge(3, 4);
		g.add_Edge(3, 5);

		g.number_of_bridges();

	}
	return 0;
}
