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
int longestcommonsubsequence(int arr[], int n)
{
	unordered_set<int> s;
	for (int i = 0; i < n; i++)
	{
		s.insert(arr[i]);
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		if (s.find(arr[i] - 1) != s.end())
		{
			continue;
		}
		else
		{
			int x = arr[i];
			int count = 0;
			while (s.find(x) != s.end())
			{
				count++;
				x++;
			}
			ans = max(count, ans);
		}
	}
	return ans;
}
int32_t main()
{

#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	int a[n];

	asdf(a, n);

	int b = longestcommonsubsequence(a, n);
	cout << endl << b;
	return 0;
}
