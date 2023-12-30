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



int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{
		string a;
		string b;

		getline(cin, a);
		getline(cin, b);

		unordered_map<char, int> mp;
		for (auto x : b) mp[x]++;

		unordered_map<char, int> mp1;
		string ans = "";
		int max_length = INT_MAX;

		int len = 0;
		int j = 0;

		for (int i = 0; i < a.length(); i++)
		{
			mp1[a[i]]++;
			if (mp1[a[i]] <= mp[a[i]])
			{
				len++;
			}


			if (len >= b.length())
			{
				while (mp1[a[j]] > mp[a[j]])
				{
					mp1[a[j]]--;
					j++;
				}

				int current_length = i - j + 1;
				if (current_length < max_length)
				{
					max_length = current_length;
					ans = a.substr(j, i - j + 1);
				}
			}
		}

		if (max_length == INT_MAX) cout << -1 << endl;
		else cout << ans << endl;
	}
	return 0;
}
