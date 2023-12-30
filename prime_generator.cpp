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

const int N = 1000000;
int p[N] = {0};
vector<int> prime_numbers;

void fill_array()
{
	for (int i = 3; i < N; i += 2)
	{
		p[i] = 1;
	}
	prime_numbers.push_back(2);
	for (int i = 3; i < N; i += 2)
	{
		if (p[i] == 1)
		{
			prime_numbers.push_back(i);
			for (int j = i * i; j < N; j += i)
			{
				p[j] = 0;
			}
		}
	}
	p[0] = p[1] = 0;
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
	int t;
	cin >> t;
	while (t--)
	{
		int m, n;
		cin >> m >> n;
		int size = n - m + 1;
		bool a[size] = {0};
		//0-> PRIME
		//1-> NOT PRIME
		for (auto current_prime_number : prime_numbers)
		{
			if (current_prime_number * current_prime_number > n) break;
			int starting_index;


			if (current_prime_number >= m/* && current_prime_number <= n*/)
			{
				starting_index = current_prime_number * 2;
			}
			else {
				starting_index = (m / current_prime_number) * current_prime_number;
			}

			//this is wrong in the case of 98..144 it will start marking from 49*2 + 2 i.e 100 and will never mark 98
			//starting_index += current_prime_number;


			for (int i = starting_index; i <= n; i += current_prime_number)
			{
				a[i - m] = 1;
			}
		}
		for (int i = m; i <= n; i++)
		{
			if (a[i - m] == 0 && i != 1)
			{
				cout << i  << endl;
			}
		}
		cout << endl;
	}
	return 0;
}
