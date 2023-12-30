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
const int MAX = 1000000;
int is_prime[MAX] = {0};
void prime_sieve(int *is_prime, int n)
{
	for (int i = 3; i < n; i += 2)
	{
		is_prime[i] = 1;
	}
	for (int i = 3; i < n; i += 2)
	{
		if (is_prime[i] == 1)
		{
			for (int j = (i * i) ; j < n ; j += i)
			{
				is_prime[j] = 0;
			}
		}
	}
	is_prime[2] = 1;
	is_prime[1] = is_prime[0] = 0;
}
vector<int> prime_numbers;
void fill_vector(int *is_prime)
{
	int i = 0;
	while (i < MAX)
	{
		if (is_prime[i] == 1)
		{
			prime_numbers.push_back(i);
		}
		i++;
	}
}
void generate_prime_factors(int n)
{
	int p = prime_numbers[0];
	int i = 0;
	map<int, int> mp;
	if (is_prime[n] == 1)
	{
		mp[n]++;
		mp[1]++;
	}
	else
	{
		while ( (p * p) <= n)
		{
			if ( n % p == 0 )
			{
				while ( n % p == 0)
				{
					n = n / p;
					mp[p]++;
				}
			}
			i++;
			p = prime_numbers[i];
		}
		if ( n != 1 )
		{
			mp[n]++;
		}
	}
	for (auto x : mp)
	{
		for (int i = 0; i < x.second; i++)
		{
			cout << x.first << " * ";
		}
	}
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
	prime_sieve(is_prime, MAX);
	fill_vector(is_prime);
	int n;
	cin >> n;
	cout << n << "  : ";
	generate_prime_factors(n);
	return 0;
}
