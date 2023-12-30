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
#define se                           second

int zero = 0;

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

bool is_palindrome(string a)
{
	for (int i = 0, j = a.length() - 1; i<a.length(), j >= 0; i++, j--)
	{
		if (a[i] != a[j])
		{
			return false;
		}
	}


	return true;
}
void palindrome_partition(int idx , string s , string curr_str)
{
	if (idx == s.length())
	{
		cout << curr_str << endl;
		return;
	}


	for (int i = idx; i < s.length(); i++)
	{
		string w = s.substr(idx, i - idx + 1);
		if (is_palindrome(w))
		{
			palindrome_partition(i + 1, s, curr_str + " " + w);
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
		string s = "abccbc";
		palindrome_partition(0, s, "");

	}
	return 0;
}
