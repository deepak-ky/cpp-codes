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
public:
	int v;
	map<int, list<int>> mp;

	graph(int v)
	{
		this->v = v;
	}


	void add_Edge(int a, int b)
	{
		mp[a].push_back(b);
	}

	bool dfs_helper(int node, bool *stack_array, bool *visited)
	{
		visited[node] = true;
		stack_array[node] = true;
		for (auto nbr : mp[node])
		{

			if (visited[nbr] == false)
			{
				bool aage_cycle_hain = dfs_helper(nbr, stack_array, visited);
				if (aage_cycle_hain == true)
				{
					return true;
				}
			}
			else
			{

				if (stack_array[nbr] == true)
				{
					return true;
				}
			}
		}

		stack_array[node] = false;
		return false;
	}


	bool detect_cycle()
	{
		bool visited[v];
		bool stack_array[v];

		for (int i = 0; i < v; i++)
		{
			visited[i] = stack_array[i] = false;
		}


		for (int i = 0; i < v; i++)
		{
			if (visited[i] == false)
			{
				if (dfs_helper(i, stack_array, visited))
				{
					return true;
				}
			}
		}

		return false;
	}
	void print_graph()
	{
		for (int i = 0; i < v; i++)
		{
			cout << i << " -> ";
			for (auto x : mp[i])
			{
				cout << x << " ";
			}
			cout << endl;
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
		graph g(3);
		g.add_Edge(0, 1);
		g.add_Edge(1, 2);
		g.add_Edge(0, 2);
		//g.add_Edge(2, 0);
		//g.add_Edge(2, 2);

		if (g.detect_cycle())
		{
			cout << "Cycle is present in the graph";
		}
		else cout << "Cycle is not present";
	}
	return 0;
}
