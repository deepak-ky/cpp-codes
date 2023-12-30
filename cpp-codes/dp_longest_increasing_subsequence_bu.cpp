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
int l_i_s(int *a, int n)
{
	int dp[100];
	//base case
	for (int i = 0; i < 100; i++)
	{
		dp[i] = 1;
	}
	int w2 = -1;
	for (int i = 1; i <= n; i++)
	{
		int ans = 1;
		for (int j = 0; j < i; j++)
		{
			if (a[i] >= a[j])
			{
				//jth element can be absorbed by ith max_element
				int w = dp[j] + 1;
				ans = max(w, ans);
			}
		}
		dp[i] = ans;
		w2 = max(w2, dp[i]);
	}

	//int w2 = *max_element(dp, dp + n + 1);
	return w2;
}
int32_t main()
{

#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	int a[] = {10, 22, 9, 33, 21, 50, 41, 60, };

	int n = sizeof(a) / sizeof(int);

	cout << l_i_s(a, n);
	return 0;
}
