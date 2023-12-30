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

int lps(string a , int i , int j)
{
	if (i == j)
	{
		return 1;
	}
	else if (i > j)
	{
		return 0;
	}
	else if (a[i] == a[j])
	{
		return 2 + lps(a, i + 1, j - 1);
	}
	else return max(lps(a, i + 1, j) , lps(a, i, j - 1)) ;
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
	string a;
	cin >> a;
	int len = a.length();
	cout << lps(a, 0, len - 1);
	return 0;
}
