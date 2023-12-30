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
	map<string, list<string> > mp;
	int cnt;
public:
	graph()
	{
		cnt = 1;
	}

	void add_edge(string a, string b)
	{
		mp[a].pb(b);
	}


	void solve(string src, vector<string> current_path)
	{
		if (src == "D")
		{
			cout << "Path " << cnt << " : ";
			cnt++;
			for (auto x : current_path)
			{
				cout << x << " ";
			}
			cout << endl;
			return;
		}

		for (auto x : mp[src])
		{
			current_path.push_back(x);
			solve(x, current_path);
			current_path.pop_back();
		}
		return;
	}

	void display_independent_paths()
	{
		string src = "S";
		vector<string> current_path;
		current_path.push_back(src);
		solve(src, current_path);

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


		//Creating the graph
		g.add_edge("S", "N1");

		g.add_edge("N1", "N2");

		g.add_edge("N2", "N3");
		g.add_edge("N3", "N4");
		g.add_edge("N3", "N5");


		g.add_edge("N5", "N6");
		g.add_edge("N4", "N6");

		g.add_edge("N2", "N7");
		g.add_edge("N6", "N7");

		g.add_edge("N7", "N15");
		g.add_edge("N7", "N8");
		g.add_edge("N8", "N9");

		g.add_edge("N9", "N11");
		g.add_edge("N9", "N10");


		g.add_edge("N11", "N12");
		g.add_edge("N12", "N14");

		g.add_edge("N11", "N13");
		g.add_edge("N13", "N14");

		g.add_edge("N15", "N16");
		g.add_edge("N15", "N17");
		g.add_edge("N16", "N18");
		g.add_edge("N17", "N18");

		g.add_edge("N14", "N18");
		g.add_edge("N18", "D");


		g.display_independent_paths();




	}
	return 0;
}
