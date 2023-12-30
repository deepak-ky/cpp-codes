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

map<int, int>  gernerate_prime_factors(int n)
{
	map<int, int> mp;
	for (int i = 2; (i * i) <= n; i++)
	{
		if (n % i == 0)
		{
			while (n % i == 0)
			{
				n = n / i;
				mp[i]++;
			}
		}
	}
	if ( n != 1)
	{
		mp[n]++;
	}
	return mp;
}
int cnt_occ(int n, int i)
{
	int ans = 0;
	int p = i;
	while (i <= n)
	{
		ans += (n / i);
		i = i * p;
	}
	return ans;
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
	test
	{
		int n, k;
		cin >> n >> k;
		int x = INT_MAX;
		map<int, int> mp = gernerate_prime_factors(k);
		for (auto y : mp)
		{
			int w = cnt_occ(n, y.first);
			x = min(x , w / y.second);
		}
		cout << x << endl;
	}
	return 0;
}
