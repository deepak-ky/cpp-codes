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
bool compare(int x, int y)
{
	if (abs(x) < abs(y))
	{
		return true;
	}
	return false;
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
		sort(a, a + n, compare);
		int ans = INT_MAX;
		int x;
		int y;
		for (int i = 1; i < n; i++)
		{
			int w = abs(a[i] + a[i - 1]);
			if (w <= ans)
			{
				ans = w;
				x = i - 1;
				y = i;
			}
		}
		cout << a[x] + a[y];
		cout << endl;
	}
	return 0;
}
