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

int dia_ans;
int dest;

void dfs_helper(int node, unordered_map<int, pair<int, int> > mp)
{

	pair<int, int> p = mp[node];

	int new_src = p.first;
	int opt_dia = p.second;

	dia_ans = min(opt_dia, dia_ans);


	if (mp.find(new_src) == mp.end())
	{
		//we have found an ending here

		dest = new_src;

		return;
	}
	else
	{
		dfs_helper(new_src, mp);
		return;
	}

	return;
}


int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{
		int n, p;
		n = 9;
		p = 6;
		int a[p] = {7, 5, 4, 2, 9, 3};
		int b[p] = {4, 9, 6, 8, 7, 1};
		int d[p] = {98, 72, 10, 22, 17, 66};

		unordered_map<int, pair<int, int> > mp;
		for (int i = 0; i < p; i++)
		{
			mp[a[i]] = {b[i], d[i]};
		}


		bool has_incoming_edge[n + 1];
		for (int i = 0; i < n + 1; i++)
		{
			has_incoming_edge[i] = false;
		}

		bool has_outgoing_edge[n + 1];
		for (int i = 0; i < n + 1; i++)
		{
			has_outgoing_edge[i] = false;
		}

		for (int i = 0; i < p; i++)
		{
			has_outgoing_edge[a[i]] = true;
		}




		//Mark all the nodes that have an incoming edge

		for (int i = 0; i < p; i++)
		{
			has_incoming_edge[b[i]] = true;
		}

		vector<vector<int>> ans;

		for (int i = 1; i < (n + 1); i++)
		{
			vector<int> v;
			if (has_incoming_edge[i] == false && has_outgoing_edge[i] == true)
			{

				//Start a dfs from this position

				v.pb(i);

				dia_ans = INT_MAX;
				dest = i;

				dfs_helper(i, mp);

				v.pb(dest);
				v.pb(dia_ans);


			}
			if (v.size() != 0)
				ans.pb(v);
		}


		cout << ans.size() << endl;

		for (auto x : ans)
		{
			for (auto y : x )
			{
				cout << y << " ";
			}
			cout << endl;
		}
	}
	return 0;
}
