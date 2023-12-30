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
	vector<int> par;
public:
	DSU(int b)
	{
		par.resize(b + 1);
		for (int i = 0; i < (b + 1); i++)
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
		else return par[x] = get_superparent(par[x]);
	}
	void unite(int a, int b)
	{
		int s_a = get_superparent(a);
		int s_b = get_superparent(b);
		if (s_a != s_b)
		{
			par[s_a] = max(s_a, s_b);
			par[s_b] = max(s_a, s_b);
		}
	}
};

class queries
{
public:
	int s;
	int e;
	int color;
};


int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{
		int n;
		cin >> n;
		DSU dsu(n);
		int q;
		cin >> q;
		queries qq[q];
		for (int i = 0; i < q; i++)
		{
			cin >> qq[i].s >> qq[i].e >> qq[i].color;
		}
		int *a = new int[n] {0};
		int j = q - 1;
		while (j != -1)
		{
			int l = qq[j].s;
			int r = qq[j].e;
			int c = qq[j].color;
			j--;
			l--;
			r--;

			int index_to_color = dsu.get_superparent(l);
			while (index_to_color <= r)
			{
				a[index_to_color] = c;
				dsu.unite(index_to_color, index_to_color + 1);
				index_to_color = dsu.get_superparent(index_to_color);
			}

		}
		for (int i = 0; i < n; i++)
		{
			cout << a[i] << endl;
		}
	}
	return 0;
}
