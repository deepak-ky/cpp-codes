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
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	int a[n];
	map<int, bool> mp1_is_present;
	map<int, int> mp1_cnt;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		mp1_is_present[a[i]] = true;
		mp1_cnt[a[i]]++;
	}
	int a1[n];
	map<int, bool> mp2_is_present;
	map<int, int> mp2_cnt;
	for (int i = 0; i < n; i++)
	{
		cin >> a1[i];
		mp2_is_present[a1[i]] = true;
		mp2_cnt[a1[i]]++;
	}
	vector<int> v;
	for (auto x : mp1_cnt)
	{
		int w = x.first;
		if (mp2_is_present[w])
		{
			int c = min(mp1_cnt[w], mp2_cnt[w]);
			for (int i = 0; i < c; i++)
			{
				v.push_back(w);
			}
		}
	}
	cout << "[";
	for (int i = 0; i < v.size() - 1; i++)
	{
		cout << v[i] << ", ";
	}
	auto it = v.end();
	it--;
	cout << *it;

	cout << "]";
	return 0;
}
