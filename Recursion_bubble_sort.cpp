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
void recbbsort(int a[], int n, int m)
{

	wer(n);
	wer(m);

	if (n == 1)
	{
		return;
	}
	else if (m == (n - 1))
	{
		recbbsort(a, n - 1, 0);
	}
	else
	{
		if (a[m] > a[m + 1])
		{
			swap(a[m], a[m + 1]);
		}
		recbbsort(a, n, m + 1);
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
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	recbbsort(a, n, 0);
	cout << "\nThe sorted array : " << endl;

	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	return 0;
}