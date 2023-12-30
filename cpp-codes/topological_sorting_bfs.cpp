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
	unordered_map<int, list<int>> mp;
public:
	graph(int v)
	{
		this->v = v;
	}

	void add_Edge(int a, int b)
	{
		mp[a].push_back(b);
	}

	void topological_sort_bfs()
	{
		unordered_map<int, int> indegree;
		queue<int> q;
		for (int i = 0; i < v; i++)
		{
			for (auto nbr : mp[i])
			{
				indegree[nbr]++;
			}
		}



		for (int i = 0; i < v; i++)
		{
			if (indegree[i] == 0)
			{
				q.push(i);
			}
		}

		vector<int> ans;

		while (!q.empty())
		{
			int f = q.front();
			q.pop();


			ans.push_back(f);

			for (auto nbr : mp[f])
			{
				indegree[nbr]--;
				if (indegree[nbr] == 0)
				{
					q.push(nbr);
				}
			}

		}


		for (auto x : ans)
		{

			cout << x << " ";
		}




	}


};

int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{
		graph g(6);
		g.add_Edge(0, 3);
		g.add_Edge(0, 5);
		g.add_Edge(3, 2);
		g.add_Edge(4, 5);
		g.add_Edge(4, 1);
		g.add_Edge(2, 1);

		g.topological_sort_bfs();

	}
	return 0;
}
