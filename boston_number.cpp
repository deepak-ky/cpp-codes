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
int generate_prime_factors(int n)
{
	bool is_prime = true;
	map<int, int> mp;
	for (int i = 2; (i * i) <= n; i++)
	{
		if (n % i == 0)
		{
			is_prime = false;
			while (n % i == 0)
			{
				n = n / i;
				mp[i]++;
			}
		}
	}
	if (is_prime == true)
	{
		mp[1]++;
		mp[n]++;
	}
	else
	{
		if (n != 1)
		{
			mp[n]++;
		}
	}
	int ans = 0;
	for (auto x : mp)
	{
		for (int i = 0; i < x.second ; i++)
		{
			cout << x.first << " * ";

		}
		string s = to_string(x.first);
		int w1 = 0;
		for (int i = 0; i < s.length(); i++)
		{
			int a = s[i] - '0';
			w1  += a;
		}
		w1 *= x.second;
		ans += w1;

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

	int n;
	cin >> n;
	int w  = generate_prime_factors(n);
	//cout << endl << w;
	int w1 = 0;
	string s = to_string(n);
	for (int i = 0; i < s.length(); i++)
	{
		int a = s[i] - '0';
		w1  += a;
	}
	if (w1 == w)
	{
		cout << "1";
	}
	else cout << "0";
	return 0;
}
