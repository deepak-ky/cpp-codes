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
public:
	int v;
	map<int, list<int>> mp;

	graph(int v)
	{
		this->v = v;
	}


	void add_Edge(int a, int b)
	{
		mp[a].push_back(b);
		mp[b].push_back(a);
	}

	void print_graph()
	{
		for (int i = 0; i < v; i++)
		{
			cout << i << " -> ";
			for (auto x : mp[i])
			{
				cout << x << " ";
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
		g.add_Edge(0, 1);
		g.add_Edge(0, 2);
		g.add_Edge(1, 2);
		g.add_Edge(2, 3);

		g.print_graph();

	}
	return 0;
}
