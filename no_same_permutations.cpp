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
vector<vector<int> > v;
void compute_permutations(int a[], int idx, int n)
{
	if (idx == n)
	{
		vector<int> d;
		for (int i = 0; i < n; i++)
		{
			d.pb(a[i]);
		}
		v.pb(d);
		return;
	}
	vector<int> w;
	for (int i = idx; i < n; i++)
	{
		auto it = find(w.begin(), w.end(), a[i]);
		if (it != w.end()) continue;
		else w.pb(a[i]);
		swap(a[idx], a[i]);
		compute_permutations(a, idx + 1, n);

		//backtracking
		swap(a[idx], a[i]);
	}
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
		compute_permutations(a, 0, n);
		sort(v.begin(), v.end());
		for (auto x : v)
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
