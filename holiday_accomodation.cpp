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
int ans = 0;
class Graph
{
public:
	int V;
	unordered_map<int, list<pair<int, int>>> mp;
	Graph(int V)
	{
		this->V = V;
	}
	void add_edge(int a, int b, int w)
	{
		mp[a].push_back({b, w});
		mp[b].push_back({a, w});
	}

	int dfs_helper(unordered_map<int, bool> &visited , unordered_map<int, int> &nbr_cnt , int &ans , int node)
	{
		visited[node] = true;
		nbr_cnt[node] = 1;
		for (auto nbr :  mp[node])
		{
			if (!visited[nbr.first])
			{
				nbr_cnt[node] += dfs_helper(visited, nbr_cnt , ans , nbr.first);
				int nx = nbr_cnt[nbr.first];
				int ny = V - nx;
				ans += 2 * min(nx , ny) * nbr.second;
			}

		}
		return nbr_cnt[node];
	}
	void solve()
	{
		unordered_map<int, bool> visited;
		unordered_map<int, int> nbr_cnt;
		int ans = 0;
		for (int i = 1; i <= V; i++)
		{
			visited[i] = false;
			nbr_cnt[i] = 0;
		}
		//DFS Print
		dfs_helper(visited , nbr_cnt ,  ans ,  1);
		cout << ans << endl;
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
	int q = 1;
	test
	{
		int v;
		cin >> v;
		Graph g(v);
		for (int i = 0; i < v - 1; i++)
		{
			int a, b, w;
			cin >> a >> b >> w;
			g.add_edge(a, b, w);
		}
		cout << "Case #" << q << ": "; g.solve();
		q++;
	}

	return 0;
}
