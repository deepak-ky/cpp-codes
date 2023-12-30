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
	map<int, list<int> > mp;
public:
	void add_Edge(int a, int b)
	{
		//because they are directed edges
		mp[a].pb(b);
	}

	void display()
	{
		for (auto x : mp)
		{
			cout << x.first << " -> ";
			for (auto y : x.second)
			{
				cout << y << " , ";
			}
			cout << endl;
		}
	}

	int single_shortest_path(int src)
	{
		unordered_map<int , int> distance;
		queue<int> q;
		for (auto node : mp)
		{
			//Here 30 does not gettted marked
			distance[node.first] = INT_MAX;
		}
		distance[30] = INT_MAX;
		q.push(src);
		distance[src] = 0;
		while (!q.empty())
		{
			int f = q.front();
			q.pop();
			for (auto nbr : mp[f])
			{
				if (distance[nbr] == INT_MAX)
				{
					distance[nbr] = distance[f] + 1;
					q.push(nbr);
				}
			}
		}

		return distance[30];

	}
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
		int board[50] = {0};

		//Every point has the access to the next six places except the last ones
		//We are currently at position 0.
		//From here we have to move
		for (int i = 0; i < 2 * n; i++)
		{
			int a, b;
			cin >> a >> b;
			int diff = b - a;

			board[a] = diff;
		}

		//Now I have to make the edges
		graph g;
		for (int i = 1; i <= 30; i++)
		{

			for (int dice = 1; dice <= 6; dice++)
			{
				int j = i + dice;
				int val = j + board[j];
				if (val <= 30)
				{
					g.add_Edge(i, val);
				}
			}
		}

		//g.display();
		int w  = g.single_shortest_path(1);
		cout << w << endl;


	}
	return 0;
}
