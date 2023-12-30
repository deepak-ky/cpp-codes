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
	int V;
	list <pair<int, int>> *l;
public:
	Graph(int n)
	{
		V = n;
		l = new list<pair<int, int> >[l];
	}
	void add_edge(int a, int b, int wt)
	{
		l[a].push_back({b, wt});
	}
	void bellman_ford()
	{
		int * distance = new int[V];
		for (int i = 0; i < V; i++)
		{
			distance[i] = INT_MAX;
		}
		distance[0] = 0;
		for (int i = 0; i < (V - 1); i++)
		{
			for (int j = 0; j < V; j++)
			{
				for (auto nbr : l[j])
				{
					if (distance[nbr.first] > distance[i] + nbr.second)
					{
						distance[nbr.first] = distance[i] + nbr.second;
					}
				}
			}
		}
		for (int i = 0; i < V; i++)
		{
			cout << 0 << "-> " << i << " distance : " << distance[i];
		}
	}
}
int32_t main()
{
//ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	int n, e;
	Graph
	return 0;
}
