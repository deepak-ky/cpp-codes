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
	map<int, int, greater<int>> mp;
	int n;
	cin >> n;
	vector<int> v;
	for (int i = 0; i < n; i++)
	{
		int w;
		cin >> w;
		//w = max(w, abs(w));
		v.push_back(w);
		mp[v[i]]++;
	}
	for (auto x : mp)
	{
		cout << x.first << " " << x.second << endl;
	}
	int flag = false;
	int greater_till_now = 0;
	auto it = mp.begin();

	if (it->first == 0)
	{
		flag = true;
	}
	else
	{
		greater_till_now = it->second;

		it++;
		for (auto it1 = it; it1 != mp.end(); it1++)
		{
			if (greater_till_now == it1->first)
			{


				flag = true;
				break;
			}
			greater_till_now += it1->second;
		}
	}
	if (flag) cout << 1;
	else	cout << -1;

	return 0;
}
