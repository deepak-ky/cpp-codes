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
		string s;
		cin >> s;
		unordered_map<char, int> mp;
		unordered_map<char, bool> done;

		for (int i = 0; i < s.length(); i++)
		{
			mp[s[i]] = i;
		}

		int ans = 0;

		for (int i = 0; i < s.length(); i++)
		{
			if (mp[s[i]] == i)
			{
				continue;
			}
			else
			{
				if (done[s[i]] == false)
				{
					unordered_map<char, bool> sb;
					for (int j = i + 1; j < mp[s[i]]; j++)
					{
						if (sb[s[j]]  == false)
						{
							ans += 1;
							sb[s[j]] = true;
						}
					}
					done[s[i]] = true;
				}
			}
		}

		cout << ans << endl;
	}
	return 0;
}
