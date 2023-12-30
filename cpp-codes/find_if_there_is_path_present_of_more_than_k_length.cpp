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
	unordered_map<int, list<pair<int, int>>> mp;
public:
	void addEdge(int a, int b, int w)
	{
		mp[a].pb({b, w});
		mp[b].pb({a, w});
	}

	bool dfs_helper(int node, int k, int curr_dist, unordered_map<int, bool> &visited)
	{
		if (curr_dist >= k)
		{
			return true;
		}

		visited[node] = true;

		for (auto x : mp[node])
		{
			int nbr = x.first;
			int weight = x.second;
			if (visited[nbr] == false)
			{
				bool aage_sahi_hain = dfs_helper(nbr, k, curr_dist + weight, visited);
				if (aage_sahi_hain == true)
				{
					return true;
				}
			}
		}

		visited[node] = false;

		return false;


	}

	bool any_path_with_value_more_than_k(int src, int k)
	{
		unordered_map<int, bool> visited;
		for (auto x : mp)
		{
			visited[x.first] = false;
		}


		return dfs_helper(src, k, 0, visited);
	}






};



int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{

		graph g;
		g.addEdge(0, 1, 4);
		g.addEdge(0, 7, 8);
		g.addEdge(1, 2, 8);
		g.addEdge(1, 7, 11);
		g.addEdge(2, 3, 7);
		g.addEdge(2, 8, 2);
		g.addEdge(2, 5, 4);
		g.addEdge(3, 4, 9);
		g.addEdge(3, 5, 14);
		g.addEdge(4, 5, 10);
		g.addEdge(5, 6, 2);
		g.addEdge(6, 7, 1);
		g.addEdge(6, 8, 6);
		g.addEdge(7, 8, 7);


		int k = 62;
		if (g.any_path_with_value_more_than_k(0, k))
		{
			yes;
		}
		else no;


	}
	return 0;
}
