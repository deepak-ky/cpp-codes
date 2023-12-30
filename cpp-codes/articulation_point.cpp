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
	unordered_map< int, list<int>> mp;
	int current_time;
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

	void dfs(int node, int *disc, int *low, int *parent, int *ap)
	{


		disc[node] = current_time;
		low[node]  = current_time;
		current_time++;

		int child_cnt = 0;

		for (auto nbr : mp[node])
		{
			if (disc[nbr] == -1)
			{
				parent[nbr] = node;
				child_cnt++;
				dfs(nbr, disc, low, parent, ap);

				low[node] = min(low[node], low[nbr]);

				if (parent[node] == -1 && child_cnt > 1)
				{
					ap[node] = 1;
				}

				if ((parent[node] != -1) && low[nbr] >= disc[node])
				{
					ap[node] = 1;
				}
			}
			else if (parent[node] != nbr)
			{
				low[node] = min(low[node], disc[nbr]);
			}
		}
	}
	int no_articulation_point()
	{
		int disc[v];
		int low[v];
		int parent[v];
		int ap[v];

		for (int i = 0; i < v; i++)
		{
			disc[i] = low[i] = parent[i] = ap[i] = -1;
		}


		//Find the number of articulation point

		for (int i = 0; i < v; i++)
		{
			if (disc[i] == -1) // Not Visited
			{
				dfs(i, disc, low, parent, ap);
			}
		}




		int ans = 0;
		for (int i = 0; i < v; i++)
		{
			if (ap[i] == 1) ans++;
		}

		return ans;
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

		cout << "Number of Articulation Point : " << g.no_articulation_point();
	}
	return 0;
}
