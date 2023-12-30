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
	int V;
	list<int> *l;
public:
	Graph(int V)
	{
		this->V = V;
		l = new list<int>[V];
	}
	void add_edge(int x, int y)
	{
		l[x].push_back(y);
	}
	void display()
	{
		for (int i = 0; i < V; i++)
		{
			cout << i << "->";
			for (int x : l[i])
			{
				cout << x << ",";
			}
			cout << endl;
		}
	}
	bool has_cycle_helper(int node, bool *visited, bool *stack_array)
	{
		visited[node] = true;
		stack_array[node] = true;
		for (auto every_nbr : l[node])
		{
			if (stack_array[every_nbr] == true)
			{
				return true;
			}
			else if (visited[every_nbr] == false)
			{
				bool cycle_mila = has_cycle_helper(every_nbr, visited, stack_array);
				if (cycle_mila == true)
				{
					return true;
				}
			}
		}
		stack_array[node] = false;
		return false;

	}
	bool has_cycle()
	{
		bool *visited = new bool[V];
		bool *stack_array = new bool[V];
		for (int i = 0; i < V; i++)
		{
			visited[i] = stack_array[i] = false;
		}
		return has_cycle_helper(0, visited, stack_array);
	}
};
int32_t main()
{

#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	Graph g(n);
	int a[n];
	for (int i = 0; i < n; i++)
	{
		int w;
		cin >> w;
		a[i] = w;
		if (w % n != 0)
		{
			int v = (abs(i + w) % n);
			g.add_edge(i, v);
		}
	}
	if (g.has_cycle())
	{
		cout << 1;
	}
	else cout << 0;

	return 0;
}
