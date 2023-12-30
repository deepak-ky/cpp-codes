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

class DSU
{
	int v;
	vector<int> parent;
public:
	DSU(int v)
	{
		this->v = v;
		parent.resize(v);
		for (int i = 0; i < v; i++)
		{
			parent[i] = i;
		}
	}

	int get_superparent(int x)
	{
		if (parent[x] == x)
		{
			return x;
		}
		else return parent[x] = get_superparent(parent[x]);
	}

	void unite(int a, int b)
	{
		int sp_a = get_superparent(a);
		int sp_b = get_superparent(b);

		parent[sp_a] = sp_b;
	}
};

class edge
{
public:
	int src;
	int dest;
	int wt;
};

bool compare(edge e1, edge e2)
{
	if (e1.wt <= e2.wt)
	{
		return true;
	}
	else return false;
}

int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{
		DSU dsu(9);

		int e;
		cin >> e;

		edge edges[e];

		for (int i = 0; i < e; i++)
		{
			cin >> edges[i].wt >> edges[i].src >> edges[i].dest;
		}

		sort(edges, edges + e, compare);

		int total_weight = 0;

		for (int i = 0; i < e; i++)
		{
			int a = edges[i].src;
			int b = edges[i].dest;

			int sp_a = dsu.get_superparent(a);
			int sp_b = dsu.get_superparent(b);

			if (sp_a != sp_b)
			{
				dsu.unite(a, b);
				total_weight += edges[i].wt;
			}
		}

		cout << total_weight << " ";


	}
	return 0;
}
