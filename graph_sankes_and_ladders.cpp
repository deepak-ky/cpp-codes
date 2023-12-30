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
template<typename T>
class Graph
{
	unordered_map<T , list < T > > g;
public:
	void add_edge(T x, T y)
	{
		g[x].push_back(y);

	}
	void bfs_sssp(T src, T dest)
	{
		map<T, int> dist;
		map<T, T> parent;
		queue<T> q;
		for (auto every_node : g)
		{
			int dis = every_node.first;
			dist[dis] = INT_MAX;
		}
		q.push(src);
		dist[src] = 0;
		parent[src] = src;
		while (!q.empty())
		{
			T node = q.front();
			q.pop();
			//cout << node << " ";
			for (auto w : g[node])
			{
				if (dist[w] == INT_MAX)
				{
					q.push(w);
					dist[w] = dist[node] + 1;
					parent[w] = node;
				}
			}

		}
		cout << "The min. of dices required are : " << dist[dest];
		cout << "\nThe path is : ";
		T tdemp = dest;
		while (tdemp != src)
		{
			cout << tdemp << "<---";
			tdemp = parent[tdemp];
		}
		cout << src;

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
	int board[50] = {0};

	//board values
	board[2] = 13;
	board[5] = 2;
	board[9] = 18;
	board[18] = 11;
	board[17] = -13;
	board[20] = -14;
	board[24] = -8;
	board[25] = 10;
	board[32] = -2;
	board[34] = -22;


	Graph<int> g1;
	for (int i = 0; i <= 36; i++)
	{
		for (int dice = 1; dice <= 6; dice++)
		{
			int j = i + dice;
			j += board[j];

			if (j <= 36)
			{
				g1.add_edge(i, j);
			}
		}
	}
	g1.add_edge(36, 36);
	g1.bfs_sssp(0, 36);
	return 0;
}
