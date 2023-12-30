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
bool check_and_update(int *a, int n)
{
	bool flag = false;
	for (int i = (n - 1); i >= 1; i--)
	{
		if (a[i] > a[i - 1])
		{
			flag = true;
			a[i] = a[i] - a[i - 1];
		}
	}
	if (flag) return true;
	else return false;
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
	sort(a, a + n);
	while (check_and_update(a, n))
	{
		sort(a, a + n);
	}
	cout << a[0]*n;


	return 0;
}
/ ?