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
	list<int> *l;
public:
	Graph(int V)
	{
		this->V = V;
		l = new list<int>[V];
	}
	void add_edge(int x, int y)
	{
		l[x].push_back(y);
		l[y].push_back(x);
	}
	void print()
	{
		for (int i = 0 ; i < V; i++)
		{
			cout << i << " -> ";
			for (auto x : l[i])
			{
				cout << x << ",";
			}
			cout << endl;
		}
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

	Graph g(4);
	g.add_edge(0, 1);
	g.add_edge(0, 2);
	g.add_edge(2, 3);
	g.add_edge(1, 2);
	g.print();

	return 0;
}
