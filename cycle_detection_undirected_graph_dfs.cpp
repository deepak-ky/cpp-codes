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
	map<int, list<int>> mp;
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

	bool detect_cycle_dfs_helper(int node, unordered_map<int, int> &parent, unordered_map<int, bool> &visited)
	{
		visited[node] = true;
		//let me do it my way
		for (auto nbr : mp[node])
		{
			if (visited[nbr] == true && parent[node] != nbr)
			{
				return true;
			}
			else if (visited[nbr] == false)
			{
				parent[nbr] = node;
				bool cycle_mila = detect_cycle_dfs_helper(nbr, parent, visited);
				if (cycle_mila == true) return true;
			}
		}
		return false;

	}
	bool detect_cycle_dfs()
	{
		unordered_map<int, int> parent;
		unordered_map<int, bool> visited;
		for (int i = 0; i < v; i++)
		{
			visited[i] = false;
		}
		int src = 0;
		parent[src] = src;
		for (int i = 0; i < v; i++)
		{
			if (visited[i] == false)
			{
				bool cycle_mila = detect_cycle_dfs_helper(i, parent, visited);
				if (cycle_mila == true)
				{
					return true;
				}

			}
		}
		//did not get a cycle
		return false;

	}

	bool detect_cycle_bfs()
	{
		unordered_map<int, bool> visited;
		unordered_map<int, int>  parent;
		for (int i = 0; i < v; i++)
		{
			visited[i] = false;
		}
		int src = 0;
		parent[src] = src;
		visited[src] = true;
		queue<int> q;
		q.push(src);
		while (!q.empty())
		{
			int node = q.front();
			q.pop();
			for (auto nbr : mp[node])
			{
				if (visited[nbr] == true && parent[node] != nbr)
				{
					return true;
				}
				else if (visited[nbr] == false)
				{
					visited[nbr] = true;
					parent[nbr] = node;
					q.push(nbr);

				}
			}
		}
		return false;
	}


};

int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{
		graph g(5);
		g.add_edge(1, 0);
		g.add_edge(1, 2);
		//g.add_edge(0, 2);
		//g.add_edge(0, 3);
		g.add_edge(3, 4);
		if (g.detect_cycle_dfs())
		{
			cout << "The graph has a cycle";
		}
		else cout << "The graph does not have  a cycle";
	}
	return 0;
}
