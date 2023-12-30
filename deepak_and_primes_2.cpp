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

const int N = 100000;
int a[N] = {0};
vector<int> prime_numbers;

void fill_array()
{
	for (int i = 3; i < N; i += 2)
	{
		a[i] = 1;
	}
	prime_numbers.pb(2);
	for (int i = 3; i < N; i += 2)
	{
		prime_numbers.pb(i);
		if (a[i] == 1)
		{
			for (int j = i * i; j < N; j += i)
			{
				a[j] = 0;
			}
		}
	}
	a[0] = a[1] = 0;
	a[2] = 1;
}



int32_t main()
{
	fill_array();
	init();
	int t = 1;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> m >> n;

		int size = n - m + 1;
		bool  b[size] = {0};



		for (auto current_prime_number : prime_numbers)
		{

			if (current_prime_number * current_prime_number > n)
			{
				break;
			}
			int starting_index;

			if (current_prime_number >= m)
			{
				starting_index = current_prime_number * 2;
			}
			else
			{
				starting_index = (m / current_prime_number) * current_prime_number;
			}

			for (int i = starting_index; i <= n; i += current_prime_number)
			{
				b[i - m] = 1;
			}

		}

		for (int i = 0; i < size; i++)
		{
			if (b[i] == 0 && (i + m != 1))
			{
				cout << i + m << endl;
			}
		}
		cout << endl;

	}
	return 0;
}
