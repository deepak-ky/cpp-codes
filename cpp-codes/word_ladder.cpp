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

int min_changes_Req(string starting_word, string ending_word, map<string, list<string>> mp)
{
	if (starting_word == ending_word)
	{
		return 0;
	}

	unordered_map<string, int> distance;
	unordered_map<string, bool> visited;
	queue<string> q;


	distance[starting_word] = 1;
	visited[starting_word]  = true;
	q.push(starting_word);


	while (!q.empty())
	{
		string str = q.front();
		q.pop();

		for (int i = 0; i < str.length(); i++)
		{
			string w = str.substr(0, i) + "*" + str.substr(i + 1);
			for (auto nbr : mp[w])
			{
				if (visited[nbr] == false)
				{
					visited[nbr] = true;
					distance[nbr] = distance[str] + 1;
					q.push(nbr);
				}

				if (nbr == ending_word)
				{
					return distance[nbr];
				}
			}
		}
	}


	return distance[ending_word];


}

int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{

		string starting_word;
		string ending_word;

		cin >> starting_word;
		cin >> ending_word;

		int n;
		cin >> n;

		set<string> s;
		for (int i = 0; i < n; i++)
		{
			string str;
			cin >> str;
			s.insert(str);
		}


		map<string, list<string>> mp;

		for (int i = 0; i < starting_word.length(); i++)
		{
			string w = starting_word.substr(0, i) + "*" + starting_word.substr(i + 1);
			mp[w].push_back(starting_word);
		}


		for (auto str : s)
		{
			for (int i = 0; i < str.length(); i++)
			{
				string w = str.substr(0, i) + "*" + str.substr(i + 1);
				mp[w].push_back(str);
			}
		}


		if (s.find(ending_word) == s.end())
		{
			cout << 0 << endl;
		}
		else
		{
			int ans = min_changes_Req(starting_word, ending_word, mp);
			cout << ans << endl;
		}



	}
	return 0;
}
