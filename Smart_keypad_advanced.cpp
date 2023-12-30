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
string keypad[] = { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };

string searchIn[] = {
	"prateek", "sneha", "deepak", "arnav", "shikha", "palak",
	"utkarsh", "divyam", "vidhi", "sparsh", "akku"
};

void check_substring(string a)
{
	for (int i = 0; i < 11; i++)
	{
		if (searchIn[i].find(a) != string::npos)
		{
			cout << searchIn[i] << endl;
		}
	}
}

void gen_strings(string s, int idx, string a)
{
	if (idx == s.length())
	{
		check_substring(a);
		return;
	}
	int w = s[idx] - '0';
	if (w == 1 || w == 0)
	{
		gen_strings(s, idx + 1, a + " ");
	}
	else
	{
		string curr = keypad[w];
		for (int i = 0; i < curr.length(); i++)
		{
			gen_strings(s, idx + 1, a + curr[i]);
		}
	}
	return;
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
		gen_strings(s, 0, "");
	}
	return 0;
}
