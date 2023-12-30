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
int index_ma(int *a, int n)
{
	int maxx = a[1];
	int in = 1;
	for (int i = 2; i <= n; i++)
	{
		if (a[i] > maxx)
		{
			maxx = a[i];
			in = i;
		}
	}
	return in;
}
int index_mi(int *a, int n)
{
	int minn = a[1];
	int in = 1;
	for (int i = 2; i <= n; i++)
	{
		if (a[i] <= minn)
		{
			minn = a[i];
			in = i;
		}
	}
	return in;
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
	int a[n + 1];
	a[0] = -10;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	int ans = 0;
	int index_of_max = index_ma(a, n);
	//wer(index_of_max);
	int cnt = 0;
	while (index_of_max != 1)
	{
		swap(a[index_of_max], a[index_of_max - 1]);
		//out(a, n + 1);
		cnt++;
		index_of_max--;
	}
	//wer(cnt);
	ans += (cnt);
	int cnt1 = 0;
	int index_of_min = index_mi(a, n);
	while (index_of_min != n)
	{
		swap(a[index_of_min], a[index_of_min + 1]);
		//out(a, n + 1);
		cnt1++;
		index_of_min++;
	}
	//wer(cnt1);
	ans += (cnt1);
	//swap(a[index_of_min,a[n]]);
	cout << ans << endl;

	return 0;
}
