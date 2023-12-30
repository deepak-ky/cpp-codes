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

int solve(vector<string> words, string s)
{
	int n = s.length();
	int dp[n];
	for (int i = 0; i < n; i++)
	{
		dp[i] = 0;
	}

	unordered_map<int, vector<string> > mp;

	for (int i = 0; i < n; i++)
	{
		string w = s.substr(0, i + 1);
		int len = w.length();
		for (int j = 0; j < len; j++)
		{
			string for_check = w.substr(j, len - j);
			if (find(words.begin(), words.end(), for_check) != words.end())
			{
				if (j == 0)
				{
					mp[i].pb(for_check);
					dp[i] += 1;
				}
				else
				{
					for (auto str : mp[j - 1])
					{
						string neww = str + " " + for_check;
						mp[i].pb(neww);
					}
					dp[i] += dp[j - 1];
				}
			}
		}
	}

	for (auto c : s)
	{
		cout << c << " ";
	}

	cout << endl;

	for (auto x : dp)
	{
		cout << x << " ";
	}

	for (auto x : mp)
	{
		cout << x.f  << " :  ";
		for (auto y : x.se)
		{
			cout << y << " , ";
		}
		cout << endl;
	}

	return dp[n - 1];
}

int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{


		vector<string> words = { "loves", "pep", "coding", "pepcoding", "ice", "cream", "icecream",
		                         "man", "go", "mango"
		                       };

		int n = words.size();

		string s = "pepcodinglovesmangoicecream";

		int cnt = solve(words, s);
		cout << endl;

		cout << cnt << endl;
	}
	return 0;
}
