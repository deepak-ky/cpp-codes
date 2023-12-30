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
	vector<int> size;
public:
	DSU(int v)
	{
		this->v = v;
		parent.resize(v);
		size.resize(v);
		for (int i = 0; i < v; i++)
		{
			parent[i] = i;
			size[i] = 1;
		}
	}


	int get_superparent(int node)
	{
		if (parent[node] == node)
		{
			return node;
		}
		//Path compression Optimization
		else return parent[node] = get_superparent(parent[node]);
	}

	void unite(int a, int b)
	{
		int s_a = get_superparent(a);
		int s_b = get_superparent(b);
		if (s_a != s_b)
		{
			//Union by rank
			if (size[s_a] > size[s_b])
			{
				parent[s_b] = s_a;
				size[s_a] += size[s_b];
				size[s_b] = 0;
			}
			else
			{
				parent[s_a] = s_b;
				size[s_b] += size[s_a];
				size[s_a] = 0;
			}
		}
	}

	int total_choices()
	{
		int ans = 0;
		ans = (v * (v - 1));
		ans /= 2;
		for (int i = 0; i < v; i++)
		{
			if (size[i] != 0)
			{
				ans -= ((size[i] * (size[i] - 1)) / 2);

			}
		}
		//Total number of choices - ( choices where both components are from the same size)
		return ans;
	}


};

int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{
		int vertices;
		cin >> vertices;
		DSU g(vertices);
		int edges;
		cin >> edges;
		while (edges--)
		{
			int a, b;
			cin >> a >> b;
			g.unite(a, b);
		}
		cout << g.total_choices() << endl;
	}
	return 0;
}
