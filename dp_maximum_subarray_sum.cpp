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
int calculate_max_sum(int a[], int idx, int size, int &msum, int &csum)
{
	/*if (idx >= size)
	{

	}*/
	int dp[100] = {0};
	dp[0] = (dp[0] > 0) ? dp[0] : 0;
	csum = csum + dp[0];
	for (int i = 1; i < size; i++)
	{
		dp[i] = dp[i - 1] + a[i];
		if (dp[i] <= 0) dp[i] = 0;
		msum = max(msum, dp[i]);
	}
	return msum;

}
int32_t main()
{

#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	int a[] = { -3, 2, 5, -1, 6, 3, -2, 7, -5, 2};
	int n = sizeof(a) / sizeof(int);
	int msum = INT_MIN;
	int csum = 0;
	//starting index is 0
	cout << calculate_max_sum(a, 0, n - 1, msum, csum);
	return 0;
}
