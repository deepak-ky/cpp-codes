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
set<vector<int> > ans;

void display_sums(int *a, int idx, int n, int curr_sum, int k, vector<int> v)
{
	if (curr_sum > k)
	{
		return;
	}
	if (curr_sum == k)
	{
		sort(v.begin(), v.end());
		ans.insert(v);
		return;
	}
	if (idx == n)
	{
		return;
	}
	v.pb(a[idx]);
	display_sums(a, idx + 1, n, curr_sum + a[idx], k, v);
	v.pop_back();
	display_sums(a, idx + 1, n, curr_sum, k, v);
	return;
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
		int *a = new int[n];
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		int k;
		cin >> k;
		vector<int> v;
		display_sums(a, 0, n, 0, k, v);
		for (auto x : ans)
		{
			for (auto y : x)
			{
				cout << y << " ";
			}
			cout << endl;
		}



	}
	return 0;
}
