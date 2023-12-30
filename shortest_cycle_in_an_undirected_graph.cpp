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
	unordered_map<int, list<int> > mp;
public:
	graph(int v)
	{
		this->v = v;
	}
	void add_edge(int a, int b)
	{
		mp[a].pb(b);
		mp[b].pb(a);
	}

	void short_cycle_bfs(int src, int &ans)
	{
		unordered_map<int, int> distance;
		for (int i = 0; i < v; i++)
		{
			distance[i] = INT_MAX;
		}
		distance[src] = 0;
		queue<int> q;
		q.push(src);
		while (!q.empty())
		{
			int node = q.front();
			q.pop();
			for (auto nbr : mp[node])
			{
				if (distance[nbr] == INT_MAX)
				{
					distance[nbr] = distance[node] + 1;
					q.push(nbr);
				}
				else if (distance[nbr] != distance[node] - 1)
				{

					//The neighbour is not my parent
					//cycle exists between that neighbour and me
					int c_l = distance[nbr] + distance[node] + 1;
					ans = min ( ans , c_l);
				}
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
		g.add_edge(1, 2);
		g.add_edge(1, 3);
		g.add_edge(2, 4);
		g.add_edge(2, 5);
		g.add_edge(3, 5);
		g.add_edge(4, 5);
		int ans = INT_MAX;
		for (int i = 0; i < 6; i++)
		{
			g.short_cycle_bfs(i, ans);
		}
		if (ans == INT_MAX)
		{
			cout << -1 << endl;
		}
		else cout << ans << endl;
	}
	return 0;
}
