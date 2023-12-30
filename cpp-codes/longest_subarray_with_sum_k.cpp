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
int checkforsubarray(int a[], int n, int k)
{
	unordered_map<int, int> mp;
	int pre = 0;
	int len = 0;
	for (int i = 0; i < n; i++)
	{
		pre = pre + a[i];
		if (pre == k) len = max(len, i + 1);
		if (mp.find(pre - k) != mp.end())
		{
			len = max(len, i - mp[pre - k]);
		}
		else
		{
			mp[pre] = i;
		}
	}
	return len;
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
	int k;
	cin >> k;
	asdf(a, n);

	int b = checkforsubarray(a, n, k);
	cout << endl << b;
	return 0;
}
