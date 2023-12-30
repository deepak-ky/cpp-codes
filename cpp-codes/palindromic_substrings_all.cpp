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
int cnt = 0;
void expand(string str, int low, int high)
{
	while ((low >= 0) && (high < str.length()) && (str[low] == str[high]))
	{
		cnt++;
		low--;
		high++;
	}
}
void allpalindromicsub_strings(string str)
{

	for (int i = 0; i < str.length(); i++)
	{
		expand(str, i, i);
		expand(str, i, i + 1);
	}
	cout /*"The number of substring are : " <<*/ << cnt;
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
	allpalindromicsub_strings(str);
	return 0;
}
