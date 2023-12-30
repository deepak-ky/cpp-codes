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

bool compare(pair<int, int> p1 , pair<int, int> p2)
{
	if (p1.first != p2.first)
	{
		if (p1.first < p2.first)
		{
			return true;
		}
		else return false;
	}
	else
	{
		if (p1.second < p2.second)
		{
			return true;
		}
		else return false;
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
	vector<pair<int, int>> v;
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		v.push_back({x, y});
	}
	sort(v.begin(), v.end(), compare);

	int i = 1;
	int curr_end_time = v[0].second;
	while ( i < v.size() )
	{
		if (v[i].first <= curr_end_time)
		{
			pair<int, int> p1 = v[i - 1];
			pair<int, int> p2 = v[i];
			v.erase(v.begin() + i - 1);
			v.erase(v.begin() + i - 1);
			v.insert(v.begin() + i - 1 , {p1.first, max(p1.second, p2.second)});
			curr_end_time = p2.second;
		}
		else
		{
			curr_end_time = v[i].second;
			i++;
		}

	}

	for (auto x : v)
	{
		cout << x.first << " " << x.second << " " ;
	}
	return 0;
}
