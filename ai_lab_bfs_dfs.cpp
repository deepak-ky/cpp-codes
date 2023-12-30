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

	map<char, list<char>> mp;

	void add_Edge(char x , char y)
	{
		mp[x].push_back(y);
	}
	void print_graph()
	{
		for (auto node : mp)
		{
			cout << node.first << "->";
			for (auto nbr : node.second)
			{
				cout << nbr << ", ";
			}
			cout << endl;
		}
	}
	void print_bfs(char src)
	{
		unordered_map<char, bool> visited;
		for (auto x : mp)
		{
			visited[x.first] = false;
		}
		queue<char> q;
		q.push(src);
		visited[src] = true;
		while (!q.empty())
		{
			char f = q.front();
			cout << f << " ";
			q.pop();
			for (auto nbr : mp[f])
			{
				if (!visited[nbr])
				{
					visited[nbr] = true;
					q.push(nbr);
				}
			}
		}
	}
	void dfs_helper(unordered_map<char, bool> &visited, char n)
	{
		visited[n] = true;
		cout << n << " ";
		for (auto nbr : mp[n])
		{
			if (!visited[nbr])
			{
				dfs_helper(visited, nbr);
			}
		}
		return;
	}
	void print_dfs(char src)
	{
		unordered_map<char, bool> visited;
		for (auto x : mp)
		{
			visited[x.first] = false;
		}
		dfs_helper(visited, src);
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
	g.add_Edge('S', 'A');
	g.add_Edge('S', 'B');
	g.add_Edge('S', 'C');
	g.add_Edge('A', 'D');
	g.add_Edge('A', 'E');
	g.add_Edge('A', 'G');
	g.add_Edge('B', 'G');
	g.add_Edge('C', 'G');
	g.print_graph();
	cout << endl << endl;
	cout << "BFS : "; g.print_bfs('S');
	cout << endl << endl;
	cout << "DFS : "; g.print_dfs('S');
	return 0;
}
