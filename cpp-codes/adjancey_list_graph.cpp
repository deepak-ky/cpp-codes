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
	list<int> *l;
public:
	graph(int v)
	{
		this->v = v;
		l = new list<int>[v];
	}

	void add_edge(int a, int b)
	{
		//Assuming all edges are bidirectional
		l[a].pb(b);
		l[b].pb(a);
	}

	void display_graph()
	{
		int cnt = 0;
		for (int i = 0; i < v; i++)
		{
			cout << "Vertex : " << i << " -> ";
			for (auto y : l[i])
			{
				cout << y << " , ";
			}
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
		graph g(4);
		g.add_edge(3, 2);
		g.add_edge(0, 1);
		g.add_edge(1, 2);
		g.add_edge(0, 2);
		g.display_graph();



	}
	return 0;
}
