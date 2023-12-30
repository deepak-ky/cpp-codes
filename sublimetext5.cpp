#include<iostream>
using namespace std;
#define ll long long
#define 1000005 INF
#define 1000000 INE
void prime_sieve(ll p[])
{
	for (ll i = 3; i <= INE; i += 2)
	{
		p[i] = 1;
	}

	for (ll i = 3; i <= INE; i += 2)
	{


		if (p[i] == 1)
		{

			for (ll j = (i * i); j <= INE; j = j + i)
			{

				p[j] = 0;
			}

		}
	}
	p[2] = 1;
	p[1] = p[0] = 0;
}
int main()
{
	ll p[INF] = {0};
	prime_sieve(p);
	ll csum[INF] = {0};
	for (ll i = 1; i <= INE; i++)
	{
		csum[i] = csum[i - 1] + p[i];
	}
	int q;
	cin >> q;
	while (q--)
	{
		ll a, b;
		cin >> a >> b;
		cout << csum[b] - csum[a - 1] << endl;
	}
	return 0;
}
