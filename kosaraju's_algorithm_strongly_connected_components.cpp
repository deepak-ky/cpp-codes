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
	int v;
	unordered_map<int, list<int> > mp;
	unordered_map<int, list<int> > reverse_edges;
public:
	graph(int v)
	{
		this->v = v;
	}
	void add_edge(int a, int b)
	{
		mp[a].push_back(b);
		reverse_edges[b].push_back(a);
	}

	void dfs_call(int node , unordered_map<int, bool> &visited , vector<int> &stack)
	{
		visited[node] = true;
		for (auto nbr : mp[node])
		{
			if (visited[nbr] == false)
			{
				dfs_call(nbr, visited, stack);
			}
		}

		//when there are no more neighbours to visit , add the node into the stack
		stack.push_back(node);
		return;
	}
	void dfs_call_2(int node , unordered_map<int, bool> &visited)
	{
		visited[node] = true;
		cout << node << " , ";
		for (auto nbr : reverse_edges[node])
		{
			if (visited[nbr] == false)
			{
				dfs_call_2(nbr, visited);
			}
		}
		return;
	}


	int number_of_connected_componenets()
	{
		vector<int> stack;
		unordered_map<int, bool> visited;
		for (int i = 0; i < v; i++)
		{
			visited[i] = false;
		}
		for (int i = 0; i < v; i++)
		{
			if (visited[i] == false)
			{

				dfs_call(i, visited, stack);
			}
		}
		for (int i = 0; i < v; i++)
		{
			visited[i] = false;
		}
		int n = stack.size();
		int cnt = 1;
		for (int i = n - 1; i >= 0; i--)
		{
			int node = stack[i];

			if (visited[node] == false)
			{
				cout << "Component " << cnt << " --> ";

				dfs_call_2(node, visited);
				cnt++;
				cout << endl;

			}

		}
		return cnt - 1;
	}

};

int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{

		graph g(7);
		g.add_edge(0, 2);
		g.add_edge(1, 0);
		g.add_edge(2, 1);
		g.add_edge(0, 3);
		g.add_edge(3, 4);
		g.add_edge(3, 5);
		g.add_edge(5, 6);
		g.add_edge(6, 3);

		int cnt = g.number_of_connected_componenets();
		cout << "The number_of_connected_componenets are : " << cnt << endl;



	}
	return 0;
}
