#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int                          long long
#define varname(name)                #name
#define mod                          998244353
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


const int n = 1000;
int a[n];
int csum[n];


void precompute()
{
	for (int i = 0; i < n; i++)
	{
		a[i] = 1;
	}

	for (int i = 2; i < n; i++)
	{
		if (a[i] == 1) // currently prime
		{
			for (int j = i * 2; j < n; j += i)
			{
				if (a[j] == 1)
				{
					a[j] = i % mod;
				}
			}
		}
	}


	a[1] = 0;

	for (int i = 2; i < n; i++)
	{
		if (a[i] == 1) //number prime hain
		{
			continue;
		}
		else
		{
			int one_factor = a[i];
			int second_factor = i / a[i];

			int ans = 0;
			ans += ((one_factor % mod) * (a[second_factor] % mod)) % mod;
			ans += ((second_factor % mod) * (a[one_factor] % mod)) % mod;

			for (int j = 2; j <= sqrt(i); j++)
			{
				if (i % j == 0 /*&&  j != one_factor && j != second_factor*/)
				{

					int w = j;
					int q = i / j;

					if (w == q)
					{
						ans += (a[w] % mod);
					}
					else
					{
						ans += (a[w] % mod);
						ans += (a[q] % mod);
					}

				}
			}


			a[i] = ans % mod;




		}
	}

	for (int i = 0; i < n; i++)
	{
		csum[i] = 0;
	}

	for (int i = 0; i < 100; i++)
	{
		cout << i << " : " << a[i] << endl;
	}



	for (int i = 1; i < n; i++)
	{
		csum[i] += a[i] + csum[i - 1];
	}

}


int32_t main()
{
	init();
	int t = 1;
	precompute();
	cin >> t;
	while (t--)
	{

		int l , r;
		cin >> l >> r;
		cout << csum[r] - csum[l - 1];
		cout << endl;

	}
	return 0;
}
