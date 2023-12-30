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
int max_teams(int *a, int n, int min_diff)
{
	sort(a, a + n);
	int s = 0;
	int e = 0;
	int cnt = 0;
	while (e < n)
	{
		int w = (a[e] - a[s]);
		if (w >= min_diff)
		{
			cnt++;
			s++;
			e++;
		}
		else if (w < min_diff)
		{
			e++;
		}
	}
	return cnt;
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
	int n;
	cin >> n;
	int *a = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int min_diff;
	cin >> min_diff;
	cout << max_teams(a, n, min_diff);
	return 0;
}
