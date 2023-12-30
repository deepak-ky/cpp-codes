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
	map<string, list<pair<string, int>> > mp;
public:
	void add_edge(string a, string b, bool isBidirectional, int weight)
	{
		mp[a].push_back(make_pair(b, weight));
		if (isBidirectional)
		{
			mp[b].push_back(make_pair(a, weight));
		}
	}
	void display_graph()
	{
		for (auto x : mp)
		{
			cout << x.first << " -> ";
			for (auto y : x.second)
			{
				cout << "[ " << y.first << " , " << y.second << " ],";
			}
			cout << endl;

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
		graph g;
		g.add_edge("a", "b", true, 20);
		g.add_edge("a", "c", true, 10);
		g.add_edge("b", "d", true, 40);
		g.add_edge("c", "d", true, 30);
		g.add_edge("a", "d", false, 50);
		g.display_graph();
	}
	return 0;
}
