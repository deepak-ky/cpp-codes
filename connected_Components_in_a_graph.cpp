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

//template<typename T>
class graph
{
	map<int, list<int> > mp;
public:
	void add_Edge(int a, int b)
	{
		mp[a].pb(b);
		mp[b].pb(a);
	}

	void dfs_helper(int src, unordered_map<int, bool> &visited)
	{
		visited[src] = true;
		cout << src << " ";
		for (auto nbr : mp[src])
		{
			if (visited[nbr] == false)
			{
				dfs_helper(nbr, visited);
			}
		}
		return;
	}

	void dfs(int src)
	{
		unordered_map<int, bool> visited;
		int cnt = 1;
		for (auto x : mp)
		{
			visited[x.first] = false;
		}
		for (auto x : mp)
		{
			if (visited[x.first] == false)
			{
				cout << "Component " << cnt << " : ";
				dfs_helper(x.first, visited);
				cout << endl;
				cnt++;
			}


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
		graph g;
		g.add_Edge(0, 1);
		g.add_Edge(1, 2);
		g.add_Edge(2, 3);
		g.add_Edge(0, 3);
		g.add_Edge(3, 4);
		g.add_Edge(4, 5);
		g.add_Edge(6, 7);
		g.add_Edge(6, 8);
		g.add_Edge(9, 10);
		g.dfs(3);

	}
	return 0;
}
