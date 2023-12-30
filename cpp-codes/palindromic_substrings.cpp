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
//This program works for only distinct substrings
int max_size = INT_MIN;
string max_string = "";
void expand(string str, int low, int high, set<string> &s)
{
	while ((low >= 0) && (high < str.length()) && (str[low] == str[high]))
	{
		s.insert(str.substr(low, high - low + 1));
		if ((high - low + 1) > max_size)
		{
			max_size = (high - low + 1);
			max_string = str.substr(low, high - low + 1);
		}
		low--;
		high++;
	}
}
void all_distinct_palindromicsub_strings(string str)
{
	set<string> s;
	for (int i = 0; i < str.length(); i++)
	{
		expand(str, i, i, s);
		expand(str, i, i + 1, s);
	}
	cout << /*"The number of substrings are : "  <<*/ s.size() << endl;
	//cout <</* "The longest palindromic substring is : " << */  max_string << endl;
	//cout << "The length of the longest palindromic substring is : " << max_size << endl;
	/*for (auto i : s)
	{
		cout << i << endl;
	}*/
}
int32_t main()
{
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	//This program works for only distinct palindromic substrings

	string str;
	cin >> str;
	all_distinct_palindromicsub_strings(str);
	return 0;
}
