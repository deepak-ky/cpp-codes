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
	unordered_map<int, list<int> > mp;
public:
	void add_edge(int a, int b)
	{
		mp[a].pb(b);
		mp[b].pb(a);
	}


	void dfs_helper(int src, unordered_map<int, bool> &visited, vector<int> &v)
	{
		visited[src] = true;
		v.push_back(src);
		for (auto nbr : mp[src])
		{
			if (visited[nbr] == false)
			{
				dfs_helper(nbr, visited, v);
			}
		}
		return;
	}


	vector<int> dfs()
	{
		unordered_map<int, bool> visited;

		for (auto x : mp)
		{
			visited[x.first] = false;
		}

		int src;
		for (auto x : mp)
		{
			if (x.second.size() == 1)
			{
				src = x.first;
				break;
			}
		}

		vector<int> v;
		dfs_helper(src, visited, v);
		return v;
	}

};


int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{

	}
	return 0;
}
