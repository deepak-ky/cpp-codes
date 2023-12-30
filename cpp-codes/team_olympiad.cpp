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
	map<int, int> mp;
	mp[1] = 0;
	mp[2] = 0;
	mp[3] = 0;
	int one_freq[n];
	int ox = 0;
	int two_freq[n];
	int oy = 0;
	int three_freq[n];
	int oz = 0;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		mp[x]++;
		if (x == 1)
		{
			one_freq[ox++] = i;
		}
		else if ( x == 2)
		{
			two_freq[oy++] = i;
		}
		else if (x == 3)
			three_freq[oz++] = i;

	}
	int ans = INT_MAX;
	for (auto w : mp)
	{
		ans = min(ans, w.second);
	}
	if (ans == 0)
	{
		cout << 0;
	}
	else
	{
		cout << ans << endl;
		for (int i = 0; i < ans; i++)
		{
			cout << one_freq[i] + 1 << " " << two_freq[i] + 1 << " " << three_freq[i] + 1 << " " << endl;
		}

	}

	return 0;
}
