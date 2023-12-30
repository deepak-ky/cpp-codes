#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//#define int                          long long
#define varname(name)                #name
#define mod                          1000000007
#define wer(x)                       cout<<"\n"<<varname(x)<<" here : "<<x
#define test                         int t; cin>>t; while(t--)
#define asdf(a,n)                    for(int i=0;i<n;i++)  cin>>a[i]
#define out(a,n)                     cout<<"\n"<<varname(a)<<" here is : ";for(int i=0;i<n;i++) cout<<a[i]<<" "; cout<<endl
int fact(int n)
{
	if (n <= 1) return 1;
	else return ((n % 1000003) * (fact(n - 1) % 1000003)) % 1000003;
}
void change_map(map<char, int> &mp, string a)
{
	mp.clear();
	sort(a.begin(), a.end());
	for (int i = 0; i < a.length(); i++)
	{
		mp[a[i]] = i + 1;
	}
}
int  rank_string(string a)
{
	map<char, int> mp;
	int ans = 0;
	for (int i = 0; i < a.length(); i++)
	{
		change_map(mp, a.substr(i, a.length() - i));
		int w = mp[a[i]];
		ans = (ans + ((w - 1) % 1000003) * (fact(a.length() - i - 1) % 1000003)) % 1000003;
	}
	return (ans + 1) % 1000003;
}
int/*32_t*/ main()
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
	cout << rank_string(a);
	return 0;
}
