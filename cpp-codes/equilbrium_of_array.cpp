#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int                          long long
#define varname(name)                #name
#define mod                          1000000007
#define wer(x)                       cout<<"\n"<<varname(x)<<" here : "<<x
#define test                         int t; cin>>t; while(t--)
#define asdf(a,n)                    for(int i=0;i<n;i++)  cin>>a[i]
#define asdff(a,n)                     cout<<"\n"<<varname(a)<<" here is : ";for(int i=0;i<n;i++) cout<<a[i]<<" "; cout<<endl
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
		int a[n];
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		int sum_from_left[n];
		sum_from_left[0] = a[0];
		int sum_from_right[n];
		sum_from_right[n - 1] = a[n - 1];
		int i, j;
		for (i = 1, j = (n - 2); i<n, j >= 0; i++, j--)
		{
			sum_from_left[i] = a[i] + sum_from_left[i - 1];
			sum_from_right[j] = a[j] + sum_from_right[j + 1];
		}
		int flag = true;
		for (int i = 0; i < n; i++)
		{
			if (sum_from_left[i] == sum_from_right[i])
			{
				flag = false;
				cout << a[i] ; break;
			}
		}
		if (flag) cout << -1;
		cout << endl;
	}
	return 0;
}
