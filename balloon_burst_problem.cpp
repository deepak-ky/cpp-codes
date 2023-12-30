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
#define se                            second

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

map< vector<int>, int > mp;

int maximum_value(vector<int> v)
{
	if (mp.find(v) != mp.end())
	{
		return mp[v];
	}
	if (v.size() == 1)
	{
		return mp[v] = v[0];
	}

	int ans = 0;

	for (int i = 0; i < v.size(); i++)
	{
		int prev;
		int current;
		int next;

		if (i == 0) prev = 1;
		else prev = v[i - 1];

		if (i == v.size() - 1) next = 1;
		else next = v[i + 1];


		current = v[i];


		v.erase(v.begin() + i);
		int opt = (prev * current * next) + maximum_value(v);
		ans = max(ans, opt);
		v.insert(v.begin() + i, current);
	}


	return mp[v] = ans;



}


int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<int> v;
		for (int i = 0; i < n; i++)
		{
			int a;
			cin >> a;
			v.push_back(a);
		}


		cout << maximum_value(v);

	}
	return 0;
}
