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
		mp[a].push_back(b);
	}
	bool dfs_helper(int node, unordered_map<int, bool> &visited, unordered_map<int, bool> &stack_array)
	{
		visited[node] = true;
		stack_array[node] = true;
		for (auto nbr : mp[node])
		{
			if (stack_array[nbr] == true)
			{
				return true;
			}
			else
			{
				if (visited[nbr] == false)
				{
					bool aage_cycle_hain = dfs_helper(nbr, visited, stack_array);
					if (aage_cycle_hain == true)
					{
						return true;
					}
				}
			}
		}
		stack_array[node] = false;
		return false;
	}
	bool dfs()
	{
		unordered_map<int, bool> visited;
		unordered_map<int, bool> stack_array;
		for (int i = 0; i < v; i++)
		{
			visited[i] = false;
			stack_array[i] = false;
		}

		for (int i = 0; i < v; i++)
		{
			bool flag = dfs_helper(i, visited, stack_array);
			if (flag == true)
			{
				return true;
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
		graph g(2);
		g.add_edge(0, 1);
		if (g.dfs())
		{
			yes;
		}
		else no;
	}
	return 0;
}
