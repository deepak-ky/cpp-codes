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
	unordered_map<int, list<int> > mp;
public:
	void add_edge(int a, int b)
	{
		mp[a].push_back(b);
	}
	int shortest_path(int src, int dest)
	{
		queue<int> q;
		unordered_map<int, int> distance;
		for (auto vertex : mp)
		{
			distance[vertex.first] = INT_MAX;
		}
		distance[src] = 0;
		q.push(src);
		while (!q.empty())
		{
			int node = q.front();
			q.pop();
			int dist = distance[node];
			for (auto nbr : mp[node])
			{
				if (distance[nbr] == INT_MAX)
				{
					q.push(nbr);
					distance[nbr] = dist + 1;
				}
			}
		}
		return distance[dest];
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
	int n = 36;
	int board[50] = {0};
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

	Graph g;
	for (int i = 0; i < 36; i++)
	{
		for (int j = 1; j <= 6; j++)
		{
			int w = i + j + board[i + j];
			if (j <= 36)
			{
				g.add_edge(i, w);
			}
		}
	}
	//g.add_edge(36, 36);
	cout << "NUmber of moves : ";
	cout << g.shortest_path(0, 36);

	return 0;
}
