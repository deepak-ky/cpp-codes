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
void print_index(int *a, int w, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] == w)
		{
			cout << i + 1 << " ";
			break;
		}
	}
}
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
	vector<int> v;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		v.push_back(x);
	}
	int flag = true;
	for (int i = 0; i < (n - 1); i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			int w = v[i] + v[j] ;
			auto itr = find(v.begin(), v.end(), w);
			if (itr != v.end())
			{
				cout << itr - v.begin() + 1 << " ";
				cout << j + 1 << " " << i + 1;
				flag = false;
				break;
			}
		}
		if (!flag)
		{
			break;
		}
	}
	if (flag)
	{
		cout << -1;
	}


	return 0;
}
