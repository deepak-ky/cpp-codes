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
int firstindex(int a[], int n, int k)
{

	int min_index = 0;
	int min_sum = 0;
	int i;
	for (int i = 0; i < k; i++)
	{


		min_sum = min_sum + a[i];
	}

	for (int j = 1; j <= (n - k); j++)
	{

		int sum = min_sum;
		sum = sum - a[j - 1];
		sum = sum + a[j + k - 1];

		if (sum <= min_sum)
		{
			min_sum = sum;
			min_index = j;
		}


	}
	return min_index;
}
int32_t main()
{

#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	int n, k;
	cin >> n >> k;

	int a[n];
	asdf(a, n);
	cout << firstindex(a, n, k) + 1;
	//out(a, n);
	return 0;
}
