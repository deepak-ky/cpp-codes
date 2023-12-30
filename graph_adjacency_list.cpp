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
	unordered_map<string , list < pair < string, int > > > g;
public:
	void add_edge(string x, string y, bool bidir, int wt)
	{
		g[x].push_back(make_pair(y, wt));
		if (bidir)
		{
			g[y].push_back(make_pair(x, wt));
		}
	}
	void print()
	{
		for (auto p : g)
		{
			cout << p.first << " -> ";
			list< pair<string, int> > w = p.second;
			for (auto q : w)
			{
				cout << "(" << q.first << "," << q.second << ")" << " , ";
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
	Graph g1;
	g1.add_edge("A", "B", true, 20);
	g1.add_edge("A", "C", true, 10);
	g1.add_edge("A", "D", false, 50);
	g1.add_edge("B", "D", true, 20);
	g1.add_edge("C", "D", true, 30);

	g1.print();



	return 0;
}
