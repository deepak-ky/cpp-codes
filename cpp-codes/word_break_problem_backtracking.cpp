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

//I should display all the answers

bool word_break(int idx, string s, vector<string> dict, string &curr_String)
{
	if (idx == s.length())
	{
		return true;
	}
	for (int i = idx; i < s.length(); i++)
	{
		string w = s.substr(idx, i - idx + 1);
		if (find(dict.begin(), dict.end(), w) != dict.end())
		{
			curr_String += w;
			bool aage_sentence_form_hua = word_break(i + 1, s, dict, curr_String);
			if (aage_sentence_form_hua == true)
			{
				cout << curr_String << endl;
				return true;
			}
			else
			{
				curr_String.erase(idx, i - idx + 1);
			}
		}
	}
	return false;
}

int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{
		vector<string> dict = {"cats", "cat", "and", "sand", "dog"};
		string s = "catsanddog";
		string ans = "";
		bool flag = word_break(0, s, dict, ans);
	}
	return 0;
}
