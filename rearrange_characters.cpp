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

// 	METHOD - 1


/*priority_queue<pair<int, char>> pq;
unordered_map<char, int> mp;

for (auto x : s) mp[x]++;
for (auto x : mp)
{
	pq.push({x.second, x.first});
}


string ans = "";

char last_character = '#';
int last_frequency  = -1;

while (!pq.empty())
{
	pair<int, int> p = pq.top();
	pq.pop();
	int freq = p.first;
	char ch  = p.second;
	ans += ch;
	freq--;

	if (last_frequency > 0)
	{
		pq.push({last_frequency, last_character});
	}


	last_frequency = freq;
	last_character = ch;
}

if (ans.length() == s.length())
{
	cout << ans << endl;
}
else cout << "No way!";
*/

class custom_compare
{
public:
	bool operator()( pair<char, int> const &p1,  pair<char, int> const &p2)
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

		//METHOD - 2 , METHOD -1 DEFINED ABOVE

		priority_queue< pair<char, int> , vector<pair<char, int>> , custom_compare > pq;

		unordered_map<char, int> mp;
		for (auto x : s) mp[x]++;

		for (auto x : mp)
		{
			pq.push({x.first, x.second});
		}

		string ans = "";
		int last_Freq = -1;
		int last_char = '#';

		while (!pq.empty())
		{
			pair<char, int> p = pq.top();
			pq.pop();
			char ch = p.first;
			ans += ch;
			int freq = p.second;
			freq--;

			if (last_Freq > 0)
			{
				pq.push({last_char, last_Freq});
			}

			last_Freq = freq;
			last_char = ch;
		}

		if (ans.length() == s.length())
		{
			cout << ans << endl;
		}
		else cout << "-1" << endl;


	}
	return 0;
}
