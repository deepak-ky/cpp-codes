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
	int vertices;
	list<pair<int, int> > edge_list;
	vector<int> parent;
public:
	DSU(int v)
	{
		vertices = v;
		parent.resize(v);
		for (int i = 0; i < v; i++)
		{
			parent[i] = i;
		}
	}

	void add_edge(int a, int b)
	{
		//all the edges are considered to be UNDIRECTED
		edge_list.pb({a, b});
	}

	//Find function
	int get_superparent(int node)
	{
		if (parent[node] == node)
		{
			return node;
		}
		else return parent[node] = get_superparent(parent[node]);
	}

	//Union Function
	bool contains_cycle()
	{
		for (auto x : edge_list)
		{
			int a = x.first;
			int b = x.second;


			int superparent_a = get_superparent(a);
			int superparent_b = get_superparent(b);



			//Both are not in the same set of students
			if (superparent_a != superparent_b)
			{
				parent[superparent_a] = superparent_b;
			}
			else
			{
				cout << "Cycle exists because of the edge between " << a << " and " << b;
				cout << endl;
				return true;
				break;
			}


		}

		//Does not contain a cycle
		return false;
	}


};


int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{
		DSU g(4);
		g.add_edge(0, 1);
		g.add_edge(1, 2);
		g.add_edge(2, 3);
		g.add_edge(3, 0);
		cout << g.contains_cycle();
	}
	return 0;
}
