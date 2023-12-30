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

void dfs_helper(int node, bool * visited, unordered_map<int, list<int>> &mp)
{
	visited[node] = true;
	for (auto nbr : mp[node])
	{
		if (visited[nbr] == false)
		{
			dfs_helper(nbr, visited, mp);
		}
	}

	return;
}
int makeConnected(int n, vector<pair<int, int>> connections)
{

	if (connections.size() < n - 1)
	{

		return -1;
	}


	unordered_map<int, list<int>> mp;
	for (auto p : connections)
	{
		mp[p.first].push_back(p.second);
		mp[p.second].push_back(p.first);
	}


	bool visited[n];
	for (int i = 0; i < n; i++)
	{
		visited[i] = false;
	}

	int num_connected_compnts = 0;

	for (int i = 0; i < n; i++)
	{
		if (visited[i] == false)
		{
			num_connected_compnts++;
			dfs_helper(i, visited, mp);
		}
	}





	return num_connected_compnts - 1;




}


int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{

		int n;
		cin >> n;


		int number_of_connections;
		cin >> number_of_connections;

		vector<pair<int, int>> connections;

		for (int i = 0; i < number_of_connections; i++)
		{
			int a, b;
			cin >> a >> b;

			connections.push_back({a, b});
		}


		cout << makeConnected(n, connections);


	}
	return 0;
}
