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
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int a[n];
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		int max_mod[n];
		int camefrom[n];
		max_mod[0] = 0;
		camefrom[0] = 0;
		for (int i = 1; i < n; i++)
		{
			int mod_here = INT_MIN;
			int cf = -1;
			for (int j = 0; j < i; j++)
			{
				int w = abs(a[j] - a[i]) + max_mod[j];
				if (w > mod_here)
				{
					mod_here = w;
					cf = j;
				}
			}
			max_mod[i] = mod_here;
			camefrom[i] = cf;
		}
		vector<int> v;

		v.push_back(a[n - 1]);
		int j = camefrom[n - 1];
		int cnt = 1;
		while (j != 0)
		{
			//wer(j);
			//wer(a[j]);
			int cur_idx = j;
			v.push_back(a[j]);
			j = camefrom[cur_idx];
			cnt++;
		}
		cout << cnt + 1 << endl;
		v.push_back(a[0]);
		reverse(v.begin(), v.end());
		for (auto x : v)
		{
			cout << x << " ";
		}
		cout << endl;
		v.clear();
	}
	return 0;
}
