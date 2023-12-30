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
	unordered_map<int, list<int>> mp;
public:
	void add_edge(int a, int b)
	{
		mp[a].pb(b);
		mp[b].pb(a);
	}

	void single_shortest_path(int src)
	{
		//distance of all the elemetns
		unordered_map<int, int> distance;
		for (auto node : mp)
		{
			distance[node.first] = INT_MAX;
		}
		distance[src] = 0;
		queue<int> q;
		q.push(src);
		while (!q.empty())
		{
			int node = q.front();
			q.pop();
			for (auto nbr : mp[node])
			{
				if (distance[nbr] == INT_MAX)
				{
					q.push(nbr);
					distance[nbr] = distance[node] + 1;

				}
			}
		}

		for (auto x : distance)
		{
			cout << src << "->" << x.first << " : " << x.second;
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
		graph g;
		g.add_edge(3, 1);
		g.add_edge(1, 2);
		g.add_edge(2, 4);
		g.add_edge(3, 4);
		g.add_edge(4, 5);
		g.single_shortest_path(3);
	}
	return 0;
}
