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
	string a;
	cin >> a;
	string b;
	cin >> b;
	unordered_map<char, int> mp;
	for (int i = 0; i < a.length(); i++)
	{
		mp[a[i]]++;
		mp[b[i]]--;
	}
	//other approach sorting
	//other approach two hash maps
	bool flag = true;
	for (auto x : mp)
	{
		if (x.second != 0)
		{
			cout << "NOT ANAGRAMS";
			cout << " because of " << x.first << endl;
			flag = false;
			break;
		}
	}
	if (flag) cout << "ANAGRAMS";

	return 0;
}
