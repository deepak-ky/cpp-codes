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

const int N = 10000007;
bitset<N> b;
vector<int> prime_numbers;

void find_prime_numbers()
{
	for (int i = 3; i < N; i += 2)
	{
		b[i] = 1;
	}
	prime_numbers.push_back(2);
	for (int i = 3; i < N; i += 2)
	{
		if (b[i])
		{
			prime_numbers.push_back(i);
			for (int j = i * i; j < N; j += i)
			{
				b[j] = 0;
			}
		}
	}
}
bool check_prime(int n)
{
	if (n <= N)
	{
		if (b[n] == 1) return true;
		else return false;
	}
	else
	{
		for (int i = 0; prime_numbers[i]*prime_numbers[i] <= n; i++)
		{
			if (n % prime_numbers[i] == 0) return false;
		}
		return true;
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
	find_prime_numbers();
	int n = 2147483647;
	cout << n << endl;
	if (check_prime(n))
	{
		cout << n << " is prime";
	}
	else cout << n << " is not prime";
	return 0;
}