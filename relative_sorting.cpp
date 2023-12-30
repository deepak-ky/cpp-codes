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
	test
	{
		map<int, int> mp;
		int n, k;
		cin >> n >> k;
		for (int i = 0; i < n; i++)
		{
			int w;
			cin >> w;
			mp[w]++;
		}
		for (int i = 0; i < k; i++)
		{
			int w;
			cin >> w;
			while (mp[w]--) cout << w << " ";
			mp.erase(w);
		}

		for (auto x : mp)
		{
			while (x.second--)
				cout << x.first << " ";
		}
		cout << endl;
	}
	return 0;
}



