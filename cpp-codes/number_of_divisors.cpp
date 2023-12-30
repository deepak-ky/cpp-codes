#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int                          long long
#define varname(name)                #name
#define mod                          1000000007
#define wer(x)                       cout<<"\n"<<varname(x)<<" here : "<<x<<"\n"
#define asdf(a,n)                    for(int i=0;i<n;i++)  cin>>a[i]
#define out(a,n)                     cout<<"\n"<<varname(a)<<" here is : \n";for(int i=0;i<n;i++) cout<<a[i]<<" "; cout<<endl
#define pb                           push_back
#define yes                          cout << "YES" << endl;
#define no                           cout << "NO"  << endl;
#define f                            first
#define s                            second

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

void prime_factorization(unordered_map<int, int> &mp , int n)
{
	for (int i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
		{
			while (n % i == 0)
			{
				mp[i]++;
				n = n / i;
			}
		}
	}
	if (n != 1)
	{
		mp[n]++;
	}
}

int32_t main()
{
	init();
	int t = 1;
	cin >> t;
	while (t--)
	{
		unordered_map<int, int> mp;
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			int w;
			cin >> w;
			prime_factorization(mp, w);
		}
		int res = 1;
		for (auto x : mp)
		{
			res = ((res % mod) * ((x.second + 1) % mod)) % mod;
		}
		cout << res % mod << endl;
	}
	return 0;
}
