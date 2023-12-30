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
	int n, m;
	cin >> n >> m;
	int a[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int b[m];
	for (int i = 0; i < m; i++)
	{
		cin >> b[i];
	}
	int w = *max_element(a, a + n);
	int w1 = *min_element(a, a + n);
	int w2 = *min_element(b, b + m);
	int ans = -1;
	int flag = 0;
	for (int i = w; i < w2; i++)
	{
		if ((2 * w1 <= i) && ( i > 0))
		{
			ans = i;
			flag = 1;
			break;
		}
	}
	if (flag)
	{
		cout << ans;
	}
	else cout << -1;

	return 0;
}
