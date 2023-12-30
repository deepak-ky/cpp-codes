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
	vector<int> par;
public:
	DSU(int v)
	{
		this->v = v;
		par.resize(v);
		for (int i = 0; i < v; i++)
		{
			par[i] = i;
		}
	}

	int get_superparent(int x)
	{
		if (x == par[x])
		{
			return x;
		}
		else  return par[x] = get_superparent(par[x]);
	}

	void unite(int a, int b)
	{
		int s_a = get_superparent(a);
		int s_b = get_superparent(b);
		if (s_a != s_b)
		{
			par[s_a] = s_b;
		}
	}
};

class edges
{
public:
	int src;
	int end;
	int wt;
};

bool compare(edges e1, edges e2)
{
	if (e1.wt < e2.wt)
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
		int v, e;
		cin >> v >> e;
		edges qe[e];
		for (int i = 0; i < e; i++)
		{
			cin >> qe[i].src >> qe[i].end >> qe[i].wt;
		}
		sort(qe, qe + e, compare);



		DSU dsu(v);
		int total_weight = 0;
		for (int i = 0; i < e; i++)
		{
			int a = qe[i].src;
			int b = qe[i].end;
			int weight = qe[i].wt;
			a--;
			b--;

			int s_a = dsu.get_superparent(a);
			int s_b = dsu.get_superparent(b);
			if (s_a != s_b)
			{
				total_weight += weight;

				dsu.unite(a, b);
			}
		}

		cout << total_weight << endl;
	}
	return 0;
}
