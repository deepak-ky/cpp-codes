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

class custom_compare
{
public:
	bool operator()(pair<char, int> const& p1 , pair<char, int> const& p2)
	{
		if (p1.second < p2.second)
		{
			return true;
		}
		else return false;
	}

};

int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{
		string s;
		cin >> s;


		unordered_map<char, int> mp;
		for (auto x : s) mp[x]++;


		priority_queue<pair<char, int> , vector<pair<char, int>> , custom_compare> pq;

		for (auto x : mp)
		{
			pq.push({x.first, x.second});
		}


		string ans = "";

		pair<int, int> p = pq.top();
		pq.pop();


		ans += p.first;
		p.second--;

		char last_char = p.first;
		int last_freq = p.second;


		while (!pq.empty())
		{

			pair<int, int> p = pq.top();
			pq.pop();


			ans += p.first;
			p.second--;

			if (last_freq != 0)
			{
				pq.push({last_char, last_freq});
			}


			last_char = p.first;
			last_freq = p.second;
		}


		if (ans.length() == s.length())
		{
			cout << ans << endl;
		}
		else cout << -1 << endl;
	}
	return 0;
}
