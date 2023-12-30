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


bool check_string(string a, int k)
{
	unordered_map<char, int> mp;
	int n = a.length();
	for (int i = 0; i < k; i++)
	{
		mp[a[i]]++;
	}

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
	int n;
	cin >> n;
	int k;
	cin >> k;
	string b;
	cin >> b;
	int n = b.length();
	string a = "";
	bool flag = false;
	for (int i = 0; i < k; i++)
	{
		unordered_map<char, int> mp;
		for (int j = i + k; j < n; j += k)
		{
			mp[a[j]]++;
		}
		if (mp['0'] != 0 && mp['1'] != 0)
		{
			flag = false;
			break;
		}
		if (mp['0'] == 0)
		{
			//aaj aaj
		}
		else if (mp['1'] == 1)
		{

		}
		else
		{

		}


	}
	return 0;
}
