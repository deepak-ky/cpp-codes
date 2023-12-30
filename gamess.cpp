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
	map<int, int> home_freq;
	map<int, int> away_freq;
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		home_freq[x]++;
		away_freq[y]++;
	}
	int sum = 0;
	for (auto x : away_freq)
	{
		int freq = home_freq[x.first];
		if (freq != 0)
		{
			sum += freq * x.second;
		}

	}
	cout << sum;
	return 0;
}
