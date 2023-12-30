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
	test
	{
		int n;
		cin >> n;
		int a[n];
		asdf(a, n);
		sort(a, a + n);
		int count[n];
		count[0] = 2;
		for (int i = 1; i < n; i++)
		{
			count[i] = count[i - 1] + 1;
		}
		int ans = 1;
		int flag = 0;
		for (int i = 0; i < n; i++)
		{

			if (a[i] < count[i])
			{
				flag = 1;
				ans = i;
			}
		}
		if (flag == 0)
		{
			cout << ans << endl;
		}
		else cout << ans + 2 << endl;
	}
	return 0;
}
