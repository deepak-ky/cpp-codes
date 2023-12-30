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

bool all_characters_match(unordered_map<char, int> mp1, unordered_map<char, int> mp2)
{
	for (auto x : mp2)
	{
		if (x.second != 0)
		{
			if (mp1[x.first] != x.second)
			{
				return false;
			}
		}
	}
	return true;
}
int32_t main()
{
//ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	string s1;
	getline(cin , s1);
	string s2;
	getline(cin, s2);

	unordered_map<char, int> map_s2;
	unordered_map<char, int> map_s3;
	for (auto x : s2)
	{
		map_s2[x]++;
		map_s3[x]++;
	}
	unordered_map<char, int> mp;

	int start = 0;
	int end = 0;
	int cnt = 0;
	int ans_len = INT_MAX;
	string ans = "";

	while (end < s1.length())
	{
		char ch = s1[end];
		mp[ch]++;
		if (map_s3[ch] != 0 && mp[ch] <= map_s3[ch])
		{
			cnt++;
		}
		while (   (mp[s1[start]] > map_s2[s1[start]]) ||  (map_s2[s1[start]] == 0))
		{
			if ((mp[s1[start]] > map_s2[s1[start]]))
				mp[s1[start]]--;
			start++;
		}

		if (cnt == s2.length() /*&& all_characters_match(mp, map_s2)*/)
		{
			string w = s1.substr(start, end - start + 1);
			if (w.length() < ans_len)
			{
				ans_len = w.length();
				ans = w;
			}
		}
		end++;

	}
	if (ans_len == INT_MAX) cout << "No String";
	else cout << ans;
	return 0;

}
