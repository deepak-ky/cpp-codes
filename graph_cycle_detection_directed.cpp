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
	void add_edge(int x, int y, bool value)
	{
		l[x].push_back(y);
		if (!value)
			l[y].push_back(x);
	}
	bool has_cycle_helper(int node, bool *visited, bool *stack_array)
	{
		//encountering a new univisted node
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
				bool cycle_mila =  has_cycle_helper(nbr, visited, stack_array);

				if (cycle_mila == true)
				{
					return true;
				}
			}
		}



		//leaving a node
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
	Graph g1(7);
	g1.add_edge(0, 1, true);
	g1.add_edge(1, 2, true);
	g1.add_edge(1, 5, true);
	g1.add_edge(2, 3, true);
	g1.add_edge(3, 4, true);
	g1.add_edge(4, 5, true);
	//g1.add_edge(4, 2, true); // back edge
	g1.add_edge(5, 6, true);

	if (g1.has_cycle())
	{
		cout << "It contains cycle ";
	}
	else cout << "It does not contain cyle";
	return 0;
}
