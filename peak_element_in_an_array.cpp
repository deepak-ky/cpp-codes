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

int peak_element(int *a, int low, int high, int n)
{
	int mid = (low + high) / 2;
	if ( (a[mid] >= a[mid - 1] || mid == 0)   && (a[mid] >= a[mid + 1] || mid == n - 1))
	{
		return mid;
	}
	else if ( a[mid] < a[mid + 1] )
	{
		return peak_element(a, mid + 1, high, n);
	}
	else return peak_element(a, low, mid - 1, n);
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
	//peak element always exists in the array
	int n;
	cin >> n;
	int *a = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	cout << peak_element(a, 0, n - 1, n);
	return 0;
}
