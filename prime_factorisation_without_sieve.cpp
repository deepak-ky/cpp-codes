#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int                          long long
#define varname(name)                #name
#define mod                          1000000007
#define wer(x)                       cout<<"\n"<<varname(x)<<" here : "<<x<<"\n"
#define test                         int t; cin>>t; while(t--)
#define asdf(a,n)                    for(int i=0;i<n;i++)  cin>>a[i]
#define out(a,n)                     cout<<"\n"<<varname(a)<<" here is : ";for(int i=0;i<n;i++) cout<<a[i]<<" "; cout<<endl
void print_prime_factors(int n)
{
	map<int, int> mp;
	for (int i = 2; i * i <= n; i++)
	{
		//in this case only prime numbers will be considered because
		//any other number which is not prime will have a prime factor
		//will alredy have been considered for eg if 18 has factors
		//1,2,3,6,9,18 in this the only prime factors are 2 and 3 therfore
		//before reaching 6 and 9 n would already become 1
		// 18/2 = 9, 9/3 = 3 , 3/3 = 1
		// expalantion for naive approach

		//in this approach as it already a square root approach if 3 and 9 are fa
		//factors then the square root of the number will lie between 3 and 9 and we will
		//i will never reach 9

		if (n % i == 0)
		{
			while (n % i == 0)
			{
				n = n / i;
				mp[i]++;
			}

		}

	}
	if (n != 1) //the number n now is a prime number
	{
		if (mp.empty())
		{
			//if the number was a prime number initially
			mp[1] = 1;
		}
		mp[n] = 1;
	}
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
	int n;
	cin >> n;
	print_prime_factors(n);
	return 0;
}
