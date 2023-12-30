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
int calculate_max_sum_optimized(int a[], int size, int &msum, int &csum)
{
	//Case for handling all the all negative numbers
	int flag = 0;
	int largest = INT_MIN;
	for (int i = 0; i < size; i++)
	{
		int w = a[i];
		largest = max(largest, w);
		if (a[i] >= 0)
		{
			flag = 1;
		}
	}
	if (flag == 0)
	{
		return largest;
	}
	else
	{
		for (int i = 0; i < size; i++)
		{
			csum = csum + a[i];

			if (csum <= 0) csum = 0;
			msum = max(msum, csum);
		}
		return msum;
	}
}
int32_t main()
{

#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	int a[] = { -2, -3, -4, -5};
	int n = sizeof(a) / sizeof(int);
	int msum = INT_MIN;
	int csum = 0;
	//starting index is 0
	cout << calculate_max_sum_optimized(a, n, msum, csum);
	return 0;
}
