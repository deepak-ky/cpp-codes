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

class graph
{
public:
	unordered_map< int , list < pair < int , int  > >  > mp;
	void add_edge(int a, int b, int w)
	{
		mp[a].push_back( {b, w});
	}
	int solve(int src , int *a, int n)
	{
		unordered_map<int, int> dist_frm_src;
		for (auto x : mp)
		{
			dist_frm_src[x.first] = INT_MAX;
		}
		dist_frm_src[src] = 0;
		set < pair <int, int> > s;
		s.insert({0, src});
		while (!s.empty())
		{
			auto f = s.begin();
			s.erase(f);
			int node = f->second;
			int curr_node_dist = f->first;
			for (auto nbr : mp[node])
			{
				if (curr_node_dist + nbr.second < dist_frm_src[nbr.first])
				{
					auto y = s.find({dist_frm_src[nbr.first] , nbr.first});
					if (y != s.end())
					{
						s.erase(y);
					}
					dist_frm_src[nbr.first] = curr_node_dist + nbr.second;
					s.insert({dist_frm_src[nbr.first] , nbr.first});

				}
			}
		}
		int t1 = dist_frm_src[n - 1] + a[n - 1];
		int t2 = dist_frm_src[n - 2] + a[n - 2];
		return min(t1, t2);


	}


};

int32_t main()
{
//ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	graph g;
	int n;
	cin >> n;
	int *a = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		if ( (i + 2) <= (n - 1))
		{
			g.add_edge(i, i + 2, a[i]);
		}
		if ( (i - 1) >= 0)
		{
			g.add_edge(i, i - 1, a[i]);
		}
	}
	cout << g.solve(0, a, n);

	return 0;
}
