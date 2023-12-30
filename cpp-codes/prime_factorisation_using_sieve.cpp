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
vector<int> prime_numbers;
void prime_sieve(int *p, int n)
{
	for (int i = 3; i <= n; i += 2)
	{
		p[i] = 1;
	}
	for (int i = 3; i <= n; i += 2)
	{
		if (p[i] == 1)
		{
			for (int j = (i * i); j <= n; j += i)
			{
				p[j] = 0;
			}
		}
	}
	p[2] = 1;
	p[1] = p[0] = 0;
}
void fill_vector(int *p)
{
	int i = 0;
	while (prime_numbers.size() != 10)
	{
		if (p[i] == 1)
		{
			prime_numbers.push_back(i);
		}
		i++;
	}
}
void primefactors(int n)
{
	int p = prime_numbers[0];
	int i = 0;
	map<int, int> mp;
	while ((p * p) <= n)
	{
		if (n % p == 0)
		{
			while (n % p == 0)
			{
				wer(n);
				n = n /  p;
				mp[p]++;
			}

		}
		i++;
		p = prime_numbers[i];
	}
	if (n != 1) mp[n]++;
	for (auto x : mp)
	{
		for (int i = 1; i <= (x.second); i++)
		{
			cout << x.first << " * ";
		}
	}
}
int32_t main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	int p[100] = {0};

	prime_sieve(p, 100);
	fill_vector(p);
	/*for (auto x : prime_numbers)
	{
		cout << x << " ";
	}*/
	test
	{
		int n;
		cin >> n;
		cout << n << " : ";
		primefactors(n);
		cout << endl;
	}
	return 0;
}
