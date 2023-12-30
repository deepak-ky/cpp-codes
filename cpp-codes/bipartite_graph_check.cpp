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
	void add_Edge(int a, int b)
	{
		mp[a].pb(b);
		mp[b].pb(a);
	}
	bool is_bipartite_helper(int node , unordered_map<int, int> &visited)
	{
		int apply_set = 3 - visited[node];
		for (auto nbr : mp[node])
		{
			if (visited[nbr] == visited[node])
			{
				return false;
			}
			if (visited[nbr] == 0)
			{
				visited[nbr] = apply_set;
				bool flag = is_bipartite_helper(nbr, visited);
				if (flag == false) return false;
			}
		}
		return true;
	}
	bool is_bipartite()
	{
		unordered_map<int, int> visited;
		//if visited[node] = 0 -> it has not been visited
		//if visited[node] = 1 -> visited , it is in set 1
		//if visited[node] = 2 -> visited , it is in set 2
		for (int i = 0; i < v; i++)
		{
			visited[i] = 0;
		}

		for (int i = 0; i < v; i++)
		{
			if (visited[i] == 0)
			{
				visited[i] = 1;
				bool flag = is_bipartite_helper(i, visited);
				if (flag == false) return false;
			}
		}
		return true;
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
		g.add_Edge(0, 3);
		g.add_Edge(1, 4);
		g.add_Edge(0, 1);
		g.add_Edge(0, 4);
		if (g.is_bipartite())
		{
			yes;
		}
		else no;
	}
	return 0;
}
