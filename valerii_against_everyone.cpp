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
#define s                            second

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
int32_t main()
{
	init();

	int t; cin >> t; while (t--)
	{
		int n;
		cin >> n;
		unordered_map<int, int> mp;
		for (int i = 0; i < n; i++)
		{
			int w;
			cin >> w;
			mp[w]++;
		}
		bool got_equal = false;
		for (auto x : mp)
		{
			if (x.second >= 2)
			{
				got_equal = true;
				break;
			}
		}
		if (got_equal)
		{
			yes;
		}
		else no;
	}


	return 0;
}
