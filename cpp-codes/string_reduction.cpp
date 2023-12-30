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
	vector<int> v1;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int w;
		cin >> w;
		v1.push_back(w);
	}
	vector<int> v2;
	unordered_map<int, int> mp;
	int n1;
	cin >> n1;
	for (int i = 0; i < n1; i++)
	{
		int w1;
		cin >> w1;
		v2.push_back(w1);
		mp[w1]++;
	}
	vector<int> new_arr;
	for (auto x : v1)
	{
		if (mp[x] > 0)
		{
			new_arr.push_back(x);
		}
	}
	unordered_map<int, int> mp1;
	for (int i = 0; i < new_arr.size(); i++)
	{
		mp1[new_arr[i]] = 1;
	}
	vector<int> new_arr_2;
	int min_opr = 0;
	if (new_arr.size() <= v2.size())
	{
		min_opr = v2.size() - new_arr.size();
	}
	for (auto x : v2)
	{
		if (mp1[x] > 0)
		{
			new_arr_2.push_back(x);
		}
	}
	int j = 0;
	int cnt = 0;
	int target = new_arr_2[j];
	int i = 0;
	while (i < new_arr.size())
	{
		if (new_arr[i] == target)
		{
			j++;
			cnt++;
			target = new_arr_2[j];
		}
		i++;
	}
	min_opr += new_arr_2.size() - cnt;
	cout << min_opr;


	return 0;
}
