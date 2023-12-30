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
		int n, x;
		cin >> n >> x;
		int a[n];
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		int sum_n = 0;
		for (int i = 0; i < n; i++)
		{
			sum_n += a[i];
		}
		int sum_1 = sum_n;
		int len = n;
		int i = 0;
		while (sum_n % x == 0 && (i < (n)))
		{
			sum_n = sum_n - a[i];
			//wer(sum_n);
			len--;
			i++;
		}

		int j = (n - 1);
		int len1 = n;
		while ((sum_1 % x == 0) && (j >= 0))
		{
			sum_1 = sum_1 - a[j];
			len1--;
			j--;
		}
		int f = max(len, len1);
		if (f == 0)
		{
			cout << -1 << endl;
		}
		else cout << f << endl;
	}

	return 0;
}
