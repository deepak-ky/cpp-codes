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
		//As these are directed edges
		mp[a].pb(b);
	}
	void topological_sort_dfs_helper(int node, unordered_map<int, bool> &visited, stack<int> &s)
	{
		visited[node] = true;
		for (auto nbr : mp[node])
		{
			if (visited[nbr] == false)
			{
				topological_sort_dfs_helper(nbr, visited, s);
			}
		}
		s.push(node);
		return;
	}
	void topological_sort_dfs()
	{
		stack<int> s;
		unordered_map<int, bool> visited;
		for (int i = 0; i < v; i++)
		{
			visited[i] = false;
		}
		for (int i = 0; i < v; i++)
		{
			if (visited[i] == false)
			{
				topological_sort_dfs_helper(i, visited, s);
			}
		}

		while (!s.empty() )
		{
			cout << s.top() << " ";
			s.pop();
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
		//This program works for only directed acyclic graph
		graph g(6);
		g.add_edge(0, 5);
		g.add_edge(4, 5);
		g.add_edge(0, 3);
		g.add_edge(3, 2);
		g.add_edge(2, 1);
		g.add_edge(4, 1);
		g.topological_sort_dfs();

	}
	return 0;
}
