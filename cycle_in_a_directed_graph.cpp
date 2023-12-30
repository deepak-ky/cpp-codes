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
	}
	bool detect_cycle_directed_dfs_helper(int node , unordered_map<int, bool> & visited, unordered_map<int, bool> & in_current_cycle)
	{
		visited[node] = true;
		in_current_cycle[node] = true;
		for (auto nbr : mp[node])
		{
			if (in_current_cycle[nbr] == true)
			{
				return true;
			}
			else if (visited[nbr] == false)
			{
				bool cycle_mila = detect_cycle_directed_dfs_helper(nbr, visited, in_current_cycle);
				if (cycle_mila == true)
				{
					return true;
				}
			}
		}

		in_current_cycle[node] = false;
		return false;
	}

	bool detect_cycle_directed_dfs()
	{
		unordered_map<int, bool> visited;
		unordered_map<int, bool> in_current_cycle;
		for (int i = 0; i < v; i++)
		{
			visited[i] = false;
		}
		for (int i = 0; i < v; i++)
		{
			if (visited[i] == false)
			{
				bool cycle_mila = detect_cycle_directed_dfs_helper(i, visited, in_current_cycle);
				if (cycle_mila) return true;
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
		graph g(7);
		g.add_edge(0, 1);
		g.add_edge(1, 5);
		g.add_edge(1, 2);
		g.add_edge(5, 6);
		g.add_edge(2, 3);
		g.add_edge(3, 4);
		//g.add_edge(4, 2);
		g.add_edge(4, 5);
		if (g.detect_cycle_directed_dfs())
		{
			cout << "Cycle exists";
		}
		else cout << "Does not exist";

	}
	return 0;
}
