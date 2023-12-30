#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int                          long long
#define varname(name)                #name
#define mod                          1000000007
#define wer(x)                       cout<<"\n"<<varname(x)<<" here : \n"<<x
#define test                         int t; cin>>t; while(t--)
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

unordered_map<int, int> find_prime_factors(int n)
{
	unordered_map<int, int> mp;
	for (int i = 2; i * i <= n; i++)
	{
		while (n % i == 0)
		{
			mp[i]++;
			n /= i;
		}
	}
	if (n != 1)
	{

		mp[n] = 1;
	}
	return mp;
}

int euler_totient(int n)
{
	unordered_map<int, int> mp = find_prime_factors(n);
	float result = n;
	for (auto x : mp)
	{
		result = result * (1.0  - 1.0 / (float)x.first);
	}
	return (int)result;
}
int32_t main()
{

	init();
	int n;
	cin >> n;
	cout << euler_totient(n);

	return 0;
}

