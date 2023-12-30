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

int modular_exponentiation(int a, int b, int c)
{
	int res = 1;
	while (b > 0)
	{
		if (b & 1)
		{
			res = ((res % c) * (a % c)) % c;
		}
		a = ((a % c) * (a % c)) % c;
		b = b >> 1;
	}
	return res % c;
}

int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{
		int n, r;
		cin >> n >> r;
		//nCr = n! / r! * (n-r)!;
		// and r <= n

		vector<int> fact(n + 1);


		fact[0] = 1;
		for (int i = 1; i < fact.size(); i++)
		{
			fact[i] = ((i % mod) * (fact[i - 1] % mod)) % mod;
		}
		int answer = 1;
		answer = ((answer % mod) * (fact[n] % mod)) % mod;
		int w = modular_exponentiation(fact[r], mod - 2, mod);
		int w1 = modular_exponentiation(fact[n - r], mod - 2, mod);
		answer = ((answer % mod) * (w % mod)) % mod;
		answer = ((answer % mod) * (w1 % mod)) % mod;
		cout << answer % mod;
	}
	return 0;
}
