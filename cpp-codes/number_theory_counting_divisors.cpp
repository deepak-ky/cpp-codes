#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int                          long long
#define varname(name)                #name
#define mod                          1000000007
#define wer(x)                       cout<<"\n"<<varname(x)<<" here : "<<x
#define test                         int t; cin>>t; while(t--)
#define asdf(a,n)                    for(int i=0;i<n;i++)  cin>>a[i]
#define out(a,n)                     cout<<"\n"<<varname(a)<<" here is : \n";for(int i=0;i<n;i++) cout<<a[i]<<" "; cout<<endl
#define pb                           push_back

const int N = 1000000;
int p[N] = {0};
vector<int> prime_numbers;

void fill_array()
{
	prime_numbers.push_back(2);
	for (int i = 3; i < N; i += 2) { p[i] = 1;}
	for (int i = 3; i < N; i += 2) {
		if (p[i] == 1)
		{
			prime_numbers.push_back(i);
			for (int j = i * i; j < N; j += i)
			{
				p[j] = 0;
			}
		}
	}
}

int count_divisors(int n)
{
	int num = n;
	map<int, int> prime_factors;
	if (find(prime_numbers.begin(), prime_numbers.end(), n) != prime_numbers.end())
	{
		return 2;
	}
	else
	{
		for (int i = 0; prime_numbers[i] * prime_numbers[i] <= n; i++)
		{
			if (n % prime_numbers[i] == 0)
			{
				while (n % prime_numbers[i] == 0)
				{
					n /= prime_numbers[i];
					prime_factors[prime_numbers[i]]++;
				}
			}



		}
		if (n != 1)
		{
			prime_factors[n]++;
		}
	}
	int cnt = 1;
	for (auto x : prime_factors)
	{
		cnt *= (x.second + 1);

	}
	return cnt;
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
	fill_array();
	cout << count_divisors(28);

	return 0;
}
