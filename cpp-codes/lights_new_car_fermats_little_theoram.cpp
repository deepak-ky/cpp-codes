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

int find_mod_for_a(string a)
{
	int n = 0;
	for (int i = 0; i < a.length() ; i++)
	{
		int w = a[i] - '0';
		n = (n * 10) % mod + w % mod;
		n = n % mod;
	}

	return n % mod;
}
int find_mod_for_b(string b)
{
	int n = 0;
	for (int i = 0; i < b.length() ; i++)
	{
		int w = b[i] - '0';
		n = (n * 10) % (mod - 1) + w % (mod - 1);
		n = n % (mod - 1);
	}

	return n % (mod - 1);
}

int fast_exponentiation(int a, int b)
{
	int ans = 1;
	while (b > 0)
	{
		if (b & 1)
		{
			ans = ((ans % mod) * (a % mod)) % mod;

		}
		a = (( a % mod) * (a % mod)) % mod ;
		b = b >> 1;
	}
	return ans % mod;
}

int32_t main()
{
	init();
	string a, b;
	cin >> a >> b;


	int x = find_mod_for_a(a);
	int y = find_mod_for_b(b);

	cout << fast_exponentiation(x, y);



	return 0;
}
