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
	unordered_set<char> s;
	unordered_map<char, list<char>> mp;
public:
	graph(unordered_set<char> s)
	{
		this->s = s;
	}
	void list_of_char(char x)
	{

	}
	void add_Edge(char a, char b)
	{
		mp[a].push_back(b);
	}

	vector<char> topological_sort()
	{
		unordered_map<char, int> indegree;
		for (auto ch : s)
		{
			indegree[ch] = 0;
		}

		for (auto x : mp)
		{
			for (auto y : x.second)
			{
				indegree[y]++;
			}
		}

		for (auto x : indegree)
		{
			cout << x.first << " " << x.second << endl;
		}

		queue<char> q;

		for (auto x : indegree)
		{
			if (x.second == 0)
			{
				q.push(x.first);
			}
		}

		vector<char> ans;

		while (!q.empty())
		{
			char f = q.front();
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



		return ans;
	}

	void print()
	{
		for (auto x : mp)
		{
			cout << x.first << " : ";
			for (auto y : x.second)
			{
				cout << y << ",";
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
		int n;
		int k;

		cin >> n;
		cin >> k;

		vector<string> dict;
		unordered_set<char> s;

		for (int i = 0; i < n; i++)
		{
			string w;
			cin >> w;
			dict.push_back(w);
			for (auto ch : w)
			{
				s.insert(ch);
			}
		}



		graph g(s);

		for (int k = 0; k < n - 1; k++)
		{
			string a = dict[k];
			string b = dict[k + 1];

			int i = 0;
			int j = 0;

			while (i < a.length() && j < b.length())
			{
				if (a[i] != b[j])
				{
					g.add_Edge(a[i], b[j]);
					break;
				}
				else
				{
					i++;
					j++;
				}
			}
		}

		g.print();

		vector<char> ans = g.topological_sort();
		cout << endl;
		cout << endl;

		for (auto x : ans)
		{
			cout << x << " ";
		}





	}
	return 0;
}
