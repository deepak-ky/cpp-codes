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

#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	n = 2 * n;
	unordered_map<char, int> mp;
	char mat[4][4];
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			char ch;
			cin >> ch;
			if (ch != '.')
			{
				mp[ch]++;
			}
		}
	}
	int flag = 1;
	for (auto x : mp)
	{
		if ((x.second) > n)
		{
			flag = 0;
			cout << "NO";
			break;

		}
	}
	if (flag)
	{
		cout << "YES";
	}

	return 0;
}
