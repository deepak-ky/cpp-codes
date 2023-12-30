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
	int *a1 = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a1[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	while (a1[n - 1] > a[0])
	{
		wer(a1[n - 1]);
		swap(a1[n - 1], a[0]);
		int j = 0;
		while (a[j] > a[j + 1] && j <= n - 2)
		{

			swap(a[j], a[j + 1]);
			j++;
		}
		int k = n - 1;
		while (a1[k] < a1[k - 1] && k >= 1)
		{

			swap(a1[k], a1[k - 1]);
			k--;
		}
		out(a1, n);
		out(a, n);

	}

	cout << (a1[n - 1] + a[0]) / 2;
	return 0;
}
