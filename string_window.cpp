#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int                          long long
#define varname(name)                #name
#define mod                          1000000007
#define wer(x)                       cout<<"\n"<<varname(x)<<" here : "<<x
#define test                         int t; cin>>t; while(t--)
#define asdf(a,n)                    for(int i=0;i<n;i++)  cin>>a[i]
#define out(a,n)                     cout<<"\n"<<varname(a)<<" here is : ";for(int i=0;i<n;i++) cout<<a[i]<<" "; cout<<endl
int32_t main()
{
	//ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	map<char, int> mp;
	for (int i = 0; i < s2.length(); i++)
	{
		mp[s2[i]]++;
	}
	int start = 0;
	int cnt = 0;
	map<char, int> mp1;
	string ans = "";
	int len = INT_MAX;
	int start_index = -1;
	for (int i = 0; i < s1.length(); i++)
	{
		mp1[s1[i]]++;
		if (mp[s1[i]] != 0 && mp[s1[i]] >= mp1[s1[i]])
		{
			//if (start == -1) start = i;
			cnt++;
		}

		if (cnt == s2.length())
		{
			while (mp1[s1[start]] > mp[s1[start]] || mp[s1[start]] == 0)
			{
				if (mp1[s1[start]] > mp[s1[start]])
					mp1[s1[start]]--;
				start++;

			}
			int len_window = i - start + 1;
			if (len_window < len)
			{
				len = len_window;
				start_index = start;
			}
		}
	}
	if (start_index == -1)
	{
		cout << "No String";
	}
	else
	{
		cout << s1.substr(start_index, len);
	}

	return 0;
}
