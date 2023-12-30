#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//#define int                          long long
#define varname(name)                #name
#define mod                          10000003
#define wer(x)                       cout<<"\n"<<varname(x)<<" here : "<<x<<"\n"
#define asdf(a,n)                    for(int i=0;i<n;i++)  cin>>a[i]
#define out(a,n)                     cout<<"\n"<<varname(a)<<" here is : \n";for(int i=0;i<n;i++) cout<<a[i]<<" "; cout<<endl
#define pb                           push_back
#define yes                          cout << "YES" << endl;
#define no                           cout << "NO"  << endl;
#define f                            first
#define se                            second

void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
}

bool can_finish(int *a, int n, int unit_paint_time , int carpenter_Cnt, long long m)
{
	long long  time = 0;
	for (int i = 0; i < n; i++)
	{
		int w = ((a[i] % mod) * (unit_paint_time % mod)) % mod;
		if (w > m)
		{
			return false;
		}
		if (((time % mod) + (w % mod)) % mod <= m)
		{
			time = ((time % mod) +  (w % mod)) % mod;
		}
		else
		{
			//I have to allocate a new carpenter , beacause the old carpenter cannot do the
			//work in <= m time
			carpenter_Cnt--;
			if (carpenter_Cnt == 0)
			{
				return false;
			}
			time = w;
			time %= mod;

		}

	}

	return true;
}

int min_time(int *a, int n, int unit_paint_time , int carpenter_Cnt)
{

	long long  l = (((*max_element(a, a + n)) % mod) * (unit_paint_time % mod)) % mod;
	long long  h = 0;
	for (int i = 0; i < n; i++)
	{
		h  =  (h % mod + a[i] % mod) % mod;
	}
	h =  ((h % mod) * (long long)(unit_paint_time % mod)) % mod;

	int ans = -1;
	while (l <= h)
	{
		long long  m = l + ((h - l) / 2);
		m = m % mod;
		if (can_finish(a, n, unit_paint_time , carpenter_Cnt, m))
		{
			ans = m % mod;
			ans %= mod;
			h = m - 1;
		}
		else
		{
			l = m + 1;
		}
	}

	return (ans + mod) % mod;
}

int/*32_t*/ main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{

		int n;
		cin >> n;
		int *a = new int[n];
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}


		int k;
		cin >> k;

		int unit_paint_time;
		cin >> unit_paint_time;


		cout << min_time(a, n, unit_paint_time , k);

	}
	return 0;
}
