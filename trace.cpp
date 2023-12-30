#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int                          long long
#define varname(name)                #name
#define mod                          1000000007
#define wer(x)                       cout<<"\n"<<varname(x)<<" here : "<<x
#define test                         int t; cin>>t; while(t--)
#define M_PI                         3.14159265358979323846
#define asdf(a,n)                    for(int i=0;i<n;i++)  cin>>a[i]
#define out(a,n)                     cout<<"\n"<<varname(a)<<" here is : ";for(int i=0;i<n;i++) cout<<a[i]<<" "; cout<<endl
int32_t main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
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
	cout << fixed << setprecision(10);
	sort(a, a + n);
	if (n & 1)
	{

		int w = a[0] * a[0];
		int sum = 0;
		for (int i = (n - 1); i >= 2; i -= 2)
		{
			sum += ((a[i] * a[i]) - (a[i - 1] * a[i - 1]));

		}
		sum += w;
		float f = sum * M_PI;
		cout << f;
	}
	else
	{
		int sum = 0;
		for (int i = (n - 1); i >= 1; i -= 2)
		{
			sum += ((a[i] * a[i]) - (a[i - 1] * a[i - 1]));

		}
		float f = sum * M_PI;
		cout << f;
	}

	return 0;
}
