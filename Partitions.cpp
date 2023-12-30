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
int partitions(int *a, int n)
{
	int cnt = 0;
	if (n <= 2) return 0;
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += a[i];
	}

	//cout << "sum here : " << sum;
	if (sum % 3 != 0)
	{
		//cout << "returning from here";
		return 0;
	}
	int sum_till_now = 0;
	int w = 0;
	for (int i = 0; i < n; i++)
	{
		sum_till_now += a[i];
		if (sum_till_now == (sum / 3))
		{
			w++;
			sum_till_now = 0;

		}
	}
	if (w < 3) return 0;
	for (int i = 1; i < (n - 1); i++)
	{
		if (a[i] == 0)
			cnt++;
	}
	return pow(2, cnt);
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
	int n;
	cin >> n; int a[n];
	vector<int> v;
	for (int i = 0; i < n; i++)
	{
		int w;
		cin >> w;
		a[i] = w;
		v.push_back(w);
	}
	cout << partitions(a, n);

	return 0;
}
