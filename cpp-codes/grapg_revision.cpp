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
class Graph_generic
{
	int v;
	unordered_map<string, list< pair<string, int> > > data;
public:
	void add_edge(string a, string b, int weight, bool val)
	{
		if (val) //directed_graph
		{
			pair<string, int> p = {b, weight};
			data[a].push_back(p);
		}
		else   //undirected graph
		{
			pair<string, int> p = {b, weight};
			pair<string, int> p1 = {a, weight};
			data[a].push_back(p);
			data[b].push_back(p1);
		}
	}
	void print()
	{
		for (auto x : data)
		{
			cout << x.first << " -> ";
			for (auto y : x.second)
			{
				cout << y.first << " " << y.second;
			}
			cout << endl;


		}
	}
	//
	/*Graph_generic g1;
	g1.add_edge("A", "B", 20, false);
	g1.add_edge("A", "C", 10, false);
	g1.add_edge("C", "D", 30, false);
	g1.add_edge("B", "D", 20, false);
	g1.add_edge("A", "D", 50, true);
	g1.print();*/
};
//list<int> topological_sort;
class Graph
{
	//int v;
	//list<int> *l;
	unordered_map<int, list<int> > l;
public:
	/*Graph(int v)
	{
		this->v = v;
		//l = new list<int>[v];
	}*/
	/*void add_edge(int a, int b)
	{
		l[a].push_back(b);
		l[b].push_back(a);
	}*/
	void add_edge(int x, int y, bool val = false)
	{
		if (val)
			l[x].push_back(y);
		else
		{
			l[x].push_back(y);
			l[y].push_back(x);

		}
	}
	/*void print_graph()
	{
		for (int i = 0; i < v; i++)
		{
			cout << i << "-> : ";
			for (auto x : l[i])
			{
				cout << x << " ";
			}
			cout << endl;
		}
	}*/
	void print_graph()
	{
		for (auto x : l)
		{
			cout << x.first << ":-";
			for (auto y : x.second)
			{
				cout << y << " ,";
			}
			cout << endl;
		}
	}
	void print_bfs(int src)
	{
		queue<int> q;
		unordered_map<int, bool> mp;
		q.push(src);
		mp[src] = true;
		while (!q.empty())
		{
			int f = q.front();
			q.pop();
			cout << f << " ";
			for (auto nbr : l[f])
			{
				if (mp[nbr] == false)
				{
					q.push(nbr);
					mp[nbr] = true;
				}
			}
		}
	}
	int shortest_path_using_bfs(int src, int dist)
	{
		queue<int> q;
		unordered_map<int, int> mp;
		for (auto x : l)  mp[x.first] = INT_MAX;
		mp[src] = 0;
		q.push(src);
		while (!q.empty())
		{
			int f = q.front();
			q.pop();
			int node = f;
			int dist = mp[f];
			for (auto nbr : l[node])
			{
				if (mp[nbr] == INT_MAX)
				{
					q.push(nbr);
					mp[nbr] = dist + 1;
				}
			}

		}
		return mp[dist];

	}
	void dfs_helper(int node, unordered_map<int, bool> &visited)
	{
		if (visited[node] == true)
		{
			return;
		}
		cout << node << " ";
		visited[node]  = true;
		for (auto nbr : l[node])
		{
			dfs_helper(nbr, visited);
		}
		//topological_sort.push_front(node);
	}
	void print_dfs(int src)
	{
		unordered_map<int, bool> visited;
		for (auto every_node : l)
		{
			visited[every_node.first] = false;
		}
		for (auto node : l)
		{
			if (!visited[node.first])
			{
				dfs_helper(node.first, visited);
			}
		}
	}
	void print_dfs_different_components()
	{
		unordered_map<int, bool> visited;
		for (auto every_node : l)
		{
			visited[every_node.first] = false;
		}
		int component = 0;
		for (auto node : l)
		{
			if (!visited[node.first])
			{
				cout << "Component " << component << " : ";
				dfs_helper(node.first, visited);
				component++;
				cout << endl;
			}
		}
	}
	void topological_sort()
	{
		unordered_map<int, int> inner_edge;
		for (auto node : l)
		{
			inner_edge[node.first] = 0;
		}
		for (auto node : l)
		{
			for (auto y : node.second)
			{
				inner_edge[y]++;
			}
		}
		queue<int> q;

		for (auto x : inner_edge)
		{
			if (x.second == 0)
			{
				q.push(x.first);
			}
		}
		while (!q.empty())
		{
			int f = q.front();
			q.pop();
			cout << f << " ";
			for (auto nbr : l[f])
			{
				inner_edge[nbr]--;
				if (inner_edge[nbr] == 0)
				{
					q.push(nbr);
				}
			}
		}
	}
	bool detect_cycle_using_bfs(int src)
	{
		unordered_map<int, bool> visited;
		for (auto x : l)
		{
			int vertex = x.first;
			visited[vertex] = false;
		}
		queue<int> q;
		unordered_map<int, int> parent;
		q.push(src);
		visited[src] = true;
		parent[src] = src;
		while (!q.empty())
		{
			int f = q.front();
			q.pop();
			for (auto nbr : l[f])
			{
				if (visited[nbr] == false)
				{
					parent[nbr] = f;
					visited[nbr] = true;
					q.push(nbr);
				}
				else
				{
					if (parent[f] != nbr)
					{
						return true;
					}
				}
			}
		}
		return false;
	}
	bool has_cycle_helper(int node, unordered_map<int, bool> &visited, unordered_map<int, bool> &stack_array)
	{
		visited[node] = true;
		stack_array[node] = true;
		for (auto nbr : l[node])
		{
			if (stack_array[nbr] == true)
			{
				return true;
			}
			else if (visited[nbr] == false)
			{
				bool cycle_mila = has_cycle_helper(nbr, visited, stack_array);
				if (cycle_mila)
				{
					return true;
				}
			}
		}
		stack_array[node] = false;
		return false;
	}
	bool has_cycle_using_dfs()
	{
		unordered_map<int, bool> visited;
		unordered_map<int, bool> stack_array;
		for (auto node : l)
		{
			visited[node.first] = stack_array[node.first] = false;
		}
		return has_cycle_helper(0, visited, stack_array);
	}
	bool cycle_detection_undirected_dfs_helper(int node, unordered_map<int, bool> &visited, int parent)
	{
		visited[node] = true;
		for (auto nbr : l[node])
		{
			if (!visited[nbr])
			{
				bool cycle_mila = cycle_detection_undirected_dfs_helper(nbr, visited, node);
				if (cycle_mila)
				{
					return true;
				}
			}
			else if (nbr != parent)
			{
				return true;
			}
			else return false;
		}
	}
	bool cycle_detection_undirected_dfs()
	{
		unordered_map<int, bool> visited;
		for (auto x : l)
		{
			visited[x.first]  = false;
		}
		return cycle_detection_undirected_dfs_helper(1, visited, -1);
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
	Graph g/*(6)*/;
	//g.add_edge(0, 1);
	//g.add_edge(0, 3);
	g.add_edge(1, 2);
	g.add_edge(2, 3);
	g.add_edge(3, 4);
	g.add_edge(4, 5);
	g.add_edge(5, 3);

	// g.add_edge(0, 1, true);
	// g.add_edge(1, 2, true);
	// g.add_edge(1, 5, true);
	// g.add_edge(2, 3, true);
	// g.add_edge(3, 4, true);
	// //g.add_edge(4, 2, true);
	// g.add_edge(4, 5, true);
	// g.add_edge(5, 6, true);
	g.print_graph();
	cout << endl;
	/*cout << "The bfs of the graph is : \n";
	g.print_bfs(0);
	  //cout << "Min distance between 0 and 5 is : " << g.shortest_path_using_bfs(0, 5);
	//bcout << endl;
	//g.print_dfs(0);
	/*cout << endl;
	for (auto x : topological_sort)
	{
		cout << x << " ";
	}*/
	//g.print_dfs_different_components();
	/*cout << "topological_sort : ";
	g.topological_sort();
	*/

	//Is Tree function/*

	/*if (g.detect_cycle_using_bfs(1))
	{
		cout << "Cycle is present in the graph";
	}
	else cout << "Cycle not present";
	*//*if (g.has_cycle_using_dfs())
{
cout << "Cycle is present in the graph";
}
else cout << "Cycle not present";
*/
	if (g.cycle_detection_undirected_dfs())
	{
		cout << "Cycle is present in the graph";
	}
	else cout << "Cycle not present";


	return 0;
}
