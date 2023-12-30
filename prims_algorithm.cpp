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
	unordered_map< int, list< pair<int, int> > > mp;
public:
	graph(int v)
	{
		this->v = v;
	}

	void add_Edge(int a, int b, int w)
	{
		mp[a].push_back({b, w});
		mp[b].push_back({a, w});
	}

	int find_min_vertex(bool *visited, int *distance)
	{
		int min_vertex = -1;
		int max_weight = INT_MAX;
		for (int i = 0; i < v; i++)
		{
			if (visited[i] == false)
			{
				if (distance[i] < max_weight)
				{
					min_vertex = i;
					max_weight = distance[i];
				}
			}
		}

		return min_vertex;
	}


	int prims()
	{
		bool visited[v];
		int distance[v];

		for (int i = 0; i < v; i++)
		{
			visited[i] = false;
			distance[i] = INT_MAX;
		}

		distance[0] = 0;

		while (1)
		{
			int min_vertex = find_min_vertex(visited, distance);

			if (min_vertex == -1)
			{
				//all the vertexes have been visited
				break;
			}

			for (auto nbr : mp[min_vertex])
			{
				int node = nbr.first;
				int current_dist = nbr.second;

				if (visited[node] == false)
				{
					if (distance[node] > current_dist)
					{
						distance[node] = current_dist;
					}
				}
			}

			visited[min_vertex] = true;
		}

		int ans = 0;
		for (int i = 0; i < v; i++)
		{
			ans += distance[i];
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

		int n, e;
		cin >> n >> e;

		graph g(n);

		for (int i = 0; i < e; i++)
		{
			int w, a, b;
			cin >> w >> a >> b;
			g.add_Edge(a, b, w);
		}

		cout << g.prims();

	}
	return 0;
}
