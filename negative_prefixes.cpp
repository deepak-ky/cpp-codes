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

bool compare(int a, int b)
{
	return a > b;
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
	test
	{
		int n;
		cin >> n;
		int *a = new int[n];
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		int *lock = new int[n];
		vector<int> v;
		for (int i = 0; i < n; i++)
		{
			cin >> lock[i];
		}
		for (int i = 0; i < n; i++)
		{
			if (lock[i] == 0)
			{
				v.push_back(a[i]);
			}
		}
		sort(v.begin(), v.end(), compare);
		int i = 0;
		int p = 0;
		vector<int> pre;
		int j = 0;
		while (i < n)
		{
			if (lock[i] == 1)
			{
				p += a[i];
				cout << a[i] << " ";
			}
			else
			{
				p += v[j];
				cout << v[j] << " ";
				j++;
			}
			pre.push_back(p);
			i++;
		}
		cout << endl;
	}
	return 0;
}
